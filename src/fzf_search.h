//
// Created by eason on 1/25/25.
//
#pragma once
// #include <bits/stl_vector.h>
#include <vector>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <array>

std::string run_command(const std::string &cmd);
std::vector<std::string, std::allocator<std::string>>
fzf_search(const std::string &input);