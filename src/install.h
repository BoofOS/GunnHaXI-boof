//
// Created by linux on 1/25/25.
//

#pragma once
#include <string>
#include <vector>

enum class install_status;

int install_package(const std::string& package);
install_status download_package(const std::string& package);
install_status install_packages(const std::vector<std::string>& package);

enum class install_status {
  INSTALL_SUCCESS,
  INSTALL_FAILED,
  DOWNLOAD_FAILED,
};
