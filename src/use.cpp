//
// Created by eason on 1/25/25.
//

#include "use.h"

void use (const std::string input) {
	std::string choice;
	std::vector<std::string> candidate = fzf_search(input);
	if (candidate.empty()) {
		std::cout << "No package found" << std::endl;
		return;
	}
	if (candidate.size() > 1) {
		//display all the candidates and ask user to choose
		std::cout << "Multiple packages found, please choose one" << std::endl;
		for (int i = 0; i < candidate.size(); i++) {
			std::cout << i+1 << ". " << candidate.at(i) << std::endl;
		}

		std::cin >> choice;
		if (std::stoi(choice) > candidate.size() || std::stoi(choice) < 1) {
			std::cout << "Invalid choice" << std::endl;
			return;
		}else {
			std::cout << "You have chosen " << candidate.at(std::stoi(choice)-1) << std::endl;
		}
		if (candidate.size() == 1) {
			std::cout << "You have chosen " << candidate.at(0) << std::endl;
			choice = "1";
		}
	}
}