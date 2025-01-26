//
// Created by eason on 1/25/25.
//
#pragma once
#include"constants.h"
#include <string>
#include <unistd.h>
#include<fzf_search.h>
#include <optional>

std::optional<std::string> query_single_package(std::vector<std::string> packages);
void use(const std::string input);
void use_internal(std::string pkg_name);
void unuse_internal(std::string pkg_name);
void unuse(const std::string input);