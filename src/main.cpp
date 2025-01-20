#include <argparse.hpp>
#include <fmt/core.h>
#include <LuaCpp.hpp>

int main()
{
    fmt::print("fmt test Hello, World!\n");
    LuaCpp::LuaContext lua;
    try {
        lua.CompileStringAndRun("print('The fastest way to start using lua in a project')");
    }
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}