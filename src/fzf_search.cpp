//
// Created by eason on 1/25/25.
//

#include "fzf_search.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include<vector>

std::string fzf_search(const std::string &input) {
	std::string fzf_command= "cat /usr/boof/Packages |/usr/bin/fzf --filter=\"" + input + "\"";
	std::string result;
	std::array<char, 128> buffer = {};
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(fzf_command.c_str(), "r"), pclose);

	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}

	return result;
}