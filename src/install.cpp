//
// Created by linux on 1/25/25.
//

#include "install.h"

#include <fzf_search.h>

install_status download_package(const std::string &package) { return install_status::INSTALL_SUCCESS; }


install_status install_packages(const std::vector<std::string>& packages) {
	for (const auto& package : packages) {
		if (download_package(package) != install_status::INSTALL_SUCCESS)
			return install_status::DOWNLOAD_FAILED;
	}

	for (const auto& package : packages) {
		//run_command()
	}
}
