#include "constants.h"
#include "download.h"
#include "fzf_search.h"
#include "install.h"
#include "update.h"
#include <LuaCpp.hpp>
#include <argparse.hpp>
#include <fmt/core.h>

#include <use.h>

int main(int argc, char** argv) {
	// argparse::ArgumentParser parser("boof");
	//
	// argparse::ArgumentParser update_command("update");
	// argparse::ArgumentParser install_command("install");
	// argparse::ArgumentParser use_command("use");
	// argparse::ArgumentParser search_command("search");
	// install_command.add_argument("packages").nargs(argparse::nargs_pattern::at_least_one);
	// search_command.add_argument("queries").nargs(argparse::nargs_pattern::at_least_one);
	//
	// parser.add_subparser(install_command);
	// parser.add_subparser(search_command);
	//
	// try {
	// 	parser.parse_args(argc, argv);
	// }
	// catch (const std::exception& err) {
	// 	std::cerr << err.what() << std::endl;
	// 	std::cerr << parser;
	// 	return 1;
	// }
	// // fmt::print("fmt test Hello, World!\n");
	// // LuaCpp::LuaContext lua;
	// // try {
	// 	// lua.CompileStringAndRun(
	// 		// "print('The fastest way to start using lua in a project')");
	// // } catch (std::runtime_error &e) {
	// 	// std::cout << e.what() << '\n';
	// // }
	// // fmt::print("hi {} \n", static_cast<int>(update()));
	// // fmt::print(fzf_search("fzf-").at(0));
	//
	// bool update_used = parser.is_subcommand_used(update_command);
	// bool use_used = parser.is_subcommand_used(use_command);
	// bool install_used = parser.is_subcommand_used(install_command);
	// bool search_used = parser.is_subcommand_used(search_command);
	//
	// switch (update_used | use_used << 1 | install_used << 2 | search_used << 3) {
	// case 0b0001: update(); break;
	// case 0b0010: use(); break;
	// case 0b0100: install_packages(install_command.get<std::vector<std::string>>("packages")); break;
	// case 0b1000: query(search_command.get<std::vector<std::string>>("queries")); break;
	// }
	update();
	install_packages({"fastfetch-2.35.0-1-x86_64",});
	// use_internal("fastfetch-2.35.0-1-x86_64");
	unuse_internal("fastfetch-2.35.0-1-x86_64");
	// std::vector<std::string> v1 = {"ab","ac"};
	// std::vector<std::string> v2 = {"ab-1","ab-2","ad-1","ac-1"};
	// std::vector<std::string> v3 = filter_by_prefix(v1, v2);
	// for (const auto &i : v3) {
	// 	fmt::print("{}\n", i);
	// }
	// std::vector<std::string>v4 =filter_by_prefix_reverse(v1, v2);
	// for (const auto &i : v4) {
	// 	fmt::print("{}\n", i);
	// }
	return 0;
}