//
// Created by linux on 1/25/25.
//

#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fzf_search.h>

enum class install_status;

int install_package(const std::string& package);
install_status download_package(const std::string& package);
install_status install_packages(const std::vector<std::string>& package);

enum class install_status {
  INSTALL_SUCCESS,
  INSTALL_FAILED,
  DOWNLOAD_SUCCESS,
  DOWNLOAD_FAILED,
};
