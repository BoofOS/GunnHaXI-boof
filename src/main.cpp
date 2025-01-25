#include <LuaCpp.hpp>
#include <argparse.hpp>
#include <fmt/core.h>

int main() {
	argparse::ArgumentParser parser("boof");

	argparse::ArgumentParser install("install");
	argparse::ArgumentParser search("search");

	parser.add_subparser(install);
	parser.add_subparser(search);

	try {
		program.parse_args(argc, argv);
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << program;
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