#include <LuaCpp.hpp>
#include <argparse.hpp>
#include <fmt/core.h>

int main(int argc, char** argv) {
	argparse::ArgumentParser parser("boof");

	argparse::ArgumentParser update_command("upgrade");
	argparse::ArgumentParser install_command("install");
	argparse::ArgumentParser search_command("search");
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
	return 0;
}