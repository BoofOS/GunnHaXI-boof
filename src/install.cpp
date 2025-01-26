//
// Created by linux on 1/25/25.
//

#include "install.h"

install_status download_package(const std::string &package) {
	return install_status::DOWNLOAD_SUCCESS;
}


install_status install_packages(const std::vector<std::string>& packages) {
	for (const auto& package : packages) {
		if (download_package(package) != install_status::DOWNLOAD_SUCCESS)
			return install_status::DOWNLOAD_FAILED;
	}

	for (const auto& package : packages) {
		//run_command()
		namespace fs = std::filesystem;
		fs::path path(BOOF_STORE_PATH);
		path += package;
		fs::create_directory(path);
		run_command("tar -xf" + path.string() + ".pkg.tar.zst -C " + path.string());
		std::remove((path.string() + ".pkg.tar.zst").c_str());
	}
}
