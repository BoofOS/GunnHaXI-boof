//
// Created by linux on 1/25/25.
//

#include "install.h"
#include "download.h"
#include "fmt/printf.h"

#include <use.h>

install_status download_package(const std::string &package) {
	download(BOOF_PACKAGE_BASE_URL + "/"+ package+".pkg.tar.zst",
			 BOOF_STORE_PATH + "/"+package+".pkg.tar.zst");
	return install_status::DOWNLOAD_SUCCESS;
}

// install_status install_packages(const std::vector<std::string> &packages) {
// 	fmt::print("Installing packages: \n");
// 	for (const auto &package : packages) {
// 		fmt::print("{}\n", package);
// 	}
// 	fmt::print("--------------------------------\n");
// 	for (const auto &package : packages) {
// 		if (download_package(package) != install_status::DOWNLOAD_SUCCESS)
// 			return install_status::DOWNLOAD_FAILED;
// 	}
// 	std::vector<std::string> unvar_deps = {};
// 	std::vector<std::string> vared_installs = {};
// 	std::vector<std::string> to_install= {};
// 	for (const auto &package : packages) {
// 		fmt::print("current package: {}\n", package);
// 		fmt::print("--------------------------------\n");
// 		// run_command()
// 		namespace fs = std::filesystem;
// 		fs::path path(BOOF_STORE_PATH);
// 		path += "/";
// 		path += package;
// 		fs::create_directory(path);
// 		run_command("tar -xf " + path.string() + ".pkg.tar.zst -C " +
// 					path.string());
// 		std::remove((path.string() + ".pkg.tar.zst").c_str());
// 		std::fstream pkginfo(path.string() + "/.PKGINFO");
// 		std::string line;
// 		while (std::getline(pkginfo, line)) {
// 			// check if line start with "depend="
// 			if (line.find("depend = ") == 0) {
// 				//get the dependencies after the "="
// 				std::string deps = line.substr(9);
// 				unvar_deps.push_back(deps);
// 			}
// 		}
// 		std::fstream buildinfo(path.string() + "/.BUILDINFO");
// 		while (std::getline(buildinfo, line)) {
// 			if (line.find("installed = ") == 0) {
// 				std::string vared_install = line.substr(12);
// 				vared_installs.push_back(vared_install);
// 			}
// 		}
// 		//compare unvar_deps and vared_installs, if they match put them in a third vecactor
// 		std::vector<std::string> filtered = filter_by_prefix(unvar_deps, vared_installs);
// 		for (const auto &dep : filtered) {
//             to_install.push_back(dep);
//         }
// 		log_download(package);
// 	}
// 	for (const auto &package : packages) {
//         log_install(package);
//     }
// 	std::fstream already_downloaded(BOOF_PACKAGE_META);
// 	std::fstream already_installed(BOOF_PACKAGE_LIST);
// 	std::string line;
// 	// remove elements from to_install that are already installed or downloaded
// 	while (std::getline(already_downloaded, line)) {
//         to_install.erase(std::remove(to_install.begin(), to_install.end(), line), to_install.end());
//     }
// 	//print to_install
// 	fmt::print("Packages to install: \n");
// 	for (const auto &package : to_install) {
// 		fmt::print("{}\n", package);
// 	}
// 	install_packages(to_install);
// 	return install_status::INSTALL_SUCCESS;
// }

//filter by prefix returns a vector of strings that have the same prefix as the elements in prefixes
std::vector<std::string> filter_by_prefix(const std::vector<std::string>& prefixes, const std::vector<std::string>& names) {
	std::vector<std::string> result;
	for (const auto& name : names) {
		for (const auto& prefix : prefixes) {
			if (name.find(prefix + "-") == 0) {
				result.push_back(name);
				break;
			}
		}
	}
	return result;
}

//filter by prefix reverse returns a vector of strings that do not have the same prefix as the elements in names
std::vector<std::string> filter_by_prefix_reverse(const std::vector<std::string>& prefixes, const std::vector<std::string>& names) {
	std::vector<std::string> result;
	for (const auto& name : names) {
		for (const auto& prefix : prefixes) {
			if (name.find(prefix + "-") == 0) {
				result.push_back(prefix);
				break;
			}
		}
	}
	// create a new vector with prefixes that are not in result and return it
	std::vector<std::string> filtered;
	for (const auto& prefix : prefixes) {
		if (std::find(result.begin(), result.end(), prefix) == result.end()) {
			filtered.push_back(prefix);
		}
	}
	return filtered;
}

// install_status install_packages(const std::vector<std::string> &package) {
// 	fmt::printf("Installing packages: \n");
// 	for (const auto &pkg : package) {
// 		fmt::printf("%s\n", pkg);
// 	}
// 	fmt::printf("--------------------------------\n");
// 	for (const auto &pkg : package) {
// 		if (download_package(pkg) != install_status::DOWNLOAD_SUCCESS) {
// 			return install_status::DOWNLOAD_FAILED;
// 		}else {
// 			log_download(pkg);
// 		}
// 	}
// 	std::vector<std::string> unvar_deps = {};
// 	std::vector<std::string> vared_deps = {};
// 	std::vector<std::string> to_install = {};
// 	std::vector<std::string> build_vared_deps = {};
// 	for (const auto &pkg : package) {
// 		fmt::printf("current package: %s\n", pkg);
// 		fmt::printf("--------------------------------\n");
// 		namespace fs = std::filesystem;
// 		fs::path path(BOOF_STORE_PATH);
// 		path += "/";
// 		path += pkg;
// 		fs::create_directory(path);
// 		run_command("tar -xf " + path.string() + ".pkg.tar.zst -C " + path.string());
// 		std::remove((path.string() + ".pkg.tar.zst").c_str());
// 		std::fstream pkginfo(path.string() + "/.PKGINFO");
// 		std::fstream buildinfo(path.string() + "/.BUILDINFO");
// 		std::string line;
// 		// read .PKGINFO file, if line starts with "depend = " and does not contain '>' or '<' or '=', then add it to unvar_deps
// 		while (std::getline(pkginfo, line)) {
// 			if (line.find("depend = ") == 0 && line.find('>') == std::string::npos && line.find('<') == std::string::npos && line.find('=') == std::string::npos) {
// 				unvar_deps.push_back(line.substr(9));
// 			}else if (line.find("depend = ") == 0){
// 				// if line starts with "depend = " and contains '>' or '<' or '=', then add it to vared_deps
// 				// get string between "depend = " and ">", or "<", or "="
// 				std::string temp = line.substr(9);
// 				vared_deps.push_back(temp.substr(0, temp.find_first_of("><=")));
// 			}
// 		}
// 		// read .BUILDINFO file, if line starts with "installed = ", then add it to build_vared_deps
// 		while (std::getline(buildinfo, line)) {
// 			if (line.find("installed = ") == 0) {
// 				build_vared_deps.push_back(line.substr(12));
// 			}
// 		}
// 		// compare vared_deps and build_vared_deps, if they match, add them to to_install
// 		std::vector<std::string> filtered = filter_by_prefix(vared_deps, build_vared_deps);
// 		// for unvar_deps check if it is already downloaded, if not use fzf_search to install the latest version
// 		std::fstream already_downloaded(BOOF_PACKAGE_META);
// 		std::vector<std::string> downloaded_packages;
// 		while (std::getline(already_downloaded, line)) {
// 			downloaded_packages.push_back(line);
// 		}
// 		unvar_deps = filter_by_prefix_reverse(unvar_deps,downloaded_packages);
// 		//search for the latest version of the package
// 		for (const auto &dep : unvar_deps) {
// 			std::vector<std::string> result = fzf_search(dep);
// 			if (result.empty()) {
// 				fmt::printf("No package found for %s\n", dep);
// 			}else {
// 				to_install.push_back(result.back());
// 			}
// 		}
// 		for (const auto &dep : filtered) {
// 			to_install.push_back(dep);
// 		}
// 	}
// 	// remove duplicates from to_install
// 	std::sort(to_install.begin(), to_install.end());
// 	to_install.erase(std::unique(to_install.begin(), to_install.end()), to_install.end());
// 	// print to_install
// 	fmt::printf("Packages to install: \n");
// 	for (const auto &pkg : to_install) {
// 		fmt::printf("%s\n", pkg);
// 	}
// 	// install the packages in to_install
// 	install_packages(to_install);
// 	return install_status::INSTALL_SUCCESS;
// }

install_status install_packages(const std::vector<std::string>& package) {
	/* 1. packages will be a vector of string that looklike pkgname-ver
	 * inside the loop
	 * 2. download the package
	 * 3. extract the package
	 * 4. delete the zst file
	 * 5. read the .PKGINFO file
	 * 6. read the .BUILDINFO file
	 * 8. parse the .PKGINFO file and get the dependencies
	 * 8.1 if the dependency does not contain any of the following characters: >, <, =, then add it to unvar_deps
	 * 8.2 if the dependency contains any of the following characters: >, <, =, then add it to vared_deps, and only get the string before the first occurence of >, <, or =
	 * 8.3 parse the .BUILDINFO file and get the installed dependencies
	 * 8.4 compared the vared_deps and build_vared_deps, if they match, add them to to_install_with_version
	 * 8.4 add the unvar_deps to to_install_without_version
	 * outside the loop
	 * 9. compress the to_install_with_version by removing duplicates
	 * 9. further compress the to_install_with_version by removing the elements that are already downloaded
	 * 10. for each element in to_install_without_version, search for the latest version of the package and put it in to_install_with_version
	 * 11. call install_packages(to_install_with_version)
	 */
	std::vector<std::string> unvar_deps = {};
	std::vector<std::string> vared_deps = {};
	std::vector<std::string> build_vared_deps = {};
	std::vector<std::string> to_install_with_version = {};
	std::vector<std::string> to_install_without_version = {};
	for (const auto &pkg : package) {
		unvar_deps = {};
		vared_deps = {};
		build_vared_deps = {};
		fmt::printf("current package: %s\n", pkg);
		fmt::printf("--------------------------------\n");
		namespace fs = std::filesystem;
		fs::path path(BOOF_STORE_PATH);
		path += "/";
		path += pkg;
		fs::create_directory(path);
		// download the package
		if (download_package(pkg) != install_status::DOWNLOAD_SUCCESS) {
			return install_status::DOWNLOAD_FAILED;
		}else {
			log_download(pkg);
		}
		run_command("tar -xf " + path.string() + ".pkg.tar.zst -C " + path.string());
		std::remove((path.string() + ".pkg.tar.zst").c_str());
		use_internal(pkg);
		std::fstream pkginfo(path.string() + "/.PKGINFO");
		std::fstream buildinfo(path.string() + "/.BUILDINFO");
		std::string line;
		while (std::getline(pkginfo, line)) {
			if (line.find("depend = ") == 0) {
				std::string sub_str = line.substr(9);
				//check for the presence of any of the following characters: >, <, =
				if (sub_str.find('>') == std::string::npos && sub_str.find('<') == std::string::npos && sub_str.find('=') == std::string::npos) {
					unvar_deps.push_back(sub_str);
				}else {
					vared_deps.push_back(sub_str.substr(0, sub_str.find_first_of("><=")));
				}
			}
		}
		while (std::getline(buildinfo, line)) {
			if (line.find("installed = ") == 0) {
				build_vared_deps.push_back(line.substr(12));
			}
		}
		std::vector<std::string> temp = filter_by_prefix(vared_deps, build_vared_deps);
		for (const auto &dep : temp) {
			to_install_with_version.push_back(dep);
		}
		for (const auto &dep : unvar_deps) {
			to_install_without_version.push_back(dep);
		}
	}
	std::sort(to_install_with_version.begin(), to_install_with_version.end());
	to_install_with_version.erase(std::unique(to_install_with_version.begin(), to_install_with_version.end()), to_install_with_version.end());
	std::fstream already_downloaded(BOOF_PACKAGE_META);
	std::vector<std::string> downloaded_packages;
	std::string line;
	while (std::getline(already_downloaded, line)) {
		downloaded_packages.push_back(line);
	}
	//compress to install_without_version by removeing elements that are not unique
	std::sort(to_install_without_version.begin(), to_install_without_version.end());
	to_install_without_version.erase(std::unique(to_install_without_version.begin(), to_install_without_version.end()), to_install_without_version.end());
	std::vector<std::string> temp = filter_by_prefix_reverse(to_install_without_version, downloaded_packages);
	for (const auto &dep : temp) {
		std::vector<std::string> result = strict_search(dep);
		if (result.empty()) {
			fmt::printf("No package found for %s\n", dep);
		}else {
			to_install_with_version.push_back(result.back());
		}
	}
	//debug:
	// fmt::printf("Packages to install: \n");
	// for (const auto &pkg : to_install_with_version) {
	// 	std::cerr << pkg << std::endl;
	// }
	if (to_install_with_version.empty()) {
		return install_status::INSTALL_SUCCESS;
	}else{
	return install_packages(to_install_with_version);
	}
}

