#include <LuaCpp.hpp>
#include <argparse.hpp>
#include <fmt/core.h>
#include "update.h"
#include "fzf_search.h"
#include "download.h"

int main(int argc, char** argv) {
	argparse::ArgumentParser parser("boof");

	argparse::ArgumentParser update_command("update");
	argparse::ArgumentParser install_command("install");
	argparse::ArgumentParser search_command("search");
	install_command.add_argument("packages").nargs(argparse::nargs_pattern::at_least_one);
	search_command.add_argument("queries").nargs(argparse::nargs_pattern::at_least_one);

	parser.add_subparser(install_command);
	parser.add_subparser(search_command);

	try {
		parser.parse_args(argc, argv);
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << parser;
		return 1;
	}
	// fmt::print("fmt test Hello, World!\n");
	// LuaCpp::LuaContext lua;
	// try {
		// lua.CompileStringAndRun(
			// "print('The fastest way to start using lua in a project')");
	// } catch (std::runtime_error &e) {
		// std::cout << e.what() << '\n';
	// }
	fmt::print("hi {}", static_cast<int>(update()));
	fmt::print(fzf_search("fzf-"));
	return 0;
}