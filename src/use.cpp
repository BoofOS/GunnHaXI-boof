//
// Created by eason on 1/25/25.
//

#include "use.h"

#include <filesystem>

std::optional<std::string>
query_single_package(std::vector<std::string> packages) {
	std::string choice;
	if (packages.empty()) {
		std::cout << "No package found" << std::endl;
		return std::nullopt;
	} else if (packages.size() == 1) {
		choice = packages[0];
	} else if (packages.size() > 1) {
		// display all the packages and ask user to choose
		std::cout << "Multiple packages found, please choose one" << std::endl;
		for (int i = 0; i < packages.size(); i++) {
			std::cout << i + 1 << ". " << packages.at(i) << std::endl;
		}

		std::cin >> choice;
		if (std::stoi(choice) > packages.size() || std::stoi(choice) < 1) {
			std::cout << "Invalid choice" << std::endl;
			return std::nullopt;
		} else {
			choice = packages.at(std::stoi(choice) - 1);
			std::cout << "You have chosen " << choice << std::endl;
		}
	}
	return choice;
}

void use(const std::string input) {
	std::vector<std::string> packages = fzf_search(input);
	auto pkg = query_single_package(packages);
	if (!pkg) {
		return;
	}

	// do stuff ...
	namespace fs = std::filesystem;
	fs::create_symlink();
}