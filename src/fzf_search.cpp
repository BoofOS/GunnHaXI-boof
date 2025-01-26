//
// Created by eason on 1/25/25.
//

#include "fzf_search.h"


std::string run_command(const std::string &cmd) {
	std::string result;
	std::array<char, 127> buffer = {};
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"),
												  pclose);

	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}

	return result;
}

std::vector<std::string> fzf_search(const std::string &input) {
	std::string result = run_command("cat "+ BOOF_PACKAGE_LIST+" | /usr/bin/fzf --filter=\"" + input + "\"");
	std::vector<std::string> result_vector;
	std::string temp;
	for (char& i : result) {
		if (i == '\n') {
			result_vector.push_back(temp);
			temp = "";
		} else {
			temp += i;
		}
	}
	return result_vector;
}
std::vector<std::string> strict_search(const std::string &input) {
	std::string result = run_command("cat "+ BOOF_PACKAGE_LIST+" | /usr/bin/grep -E ^"+input+"-[0-9].*$");
	std::vector<std::string> result_vector = {};
	std::string temp;
	for (char& i : result) {
		if (i == '\n') {
			result_vector.push_back(temp);
			temp = "";
		} else {
			temp += i;
		}
	}
	return result_vector;
}