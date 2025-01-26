//
// Created by linux on 1/25/25.
//

#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fzf_search.h>
#include<fstream>
#include"meta.h"
#include<format>
#include <iostream>

enum class install_status;

int install_package(const std::string& package);
install_status download_package(const std::string& package);
install_status install_packages(const std::vector<std::string>& package);
std::vector<std::string> filter_by_prefix(const std::vector<std::string>& prefixes, const std::vector<std::string>& names);
std::vector<std::string> filter_by_prefix_reverse(const std::vector<std::string>& prefixes, const std::vector<std::string>& names);
enum class install_status {
  INSTALL_SUCCESS,
  INSTALL_FAILED,
  DOWNLOAD_SUCCESS,
  DOWNLOAD_FAILED,
};
