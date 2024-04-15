#include "Server.h"
#include "Utility.h"

#include <iostream>
#include <string>
#include <vector>

void print_usage(const char* binary_path)
{
    std::printf("%s: <port>", binary_path);
}

int main([[maybe_unused]] const int argc, [[maybe_unused]] const char* const* const argv)
{
    const std::vector<std::string> args(argv, std::next(argv, static_cast<std::ptrdiff_t>(argc)));
    if (args.size()!=2) {
        print_usage(args[0].c_str());
        return EXIT_FAILURE;
    }
    const std::uint16_t port = noct::util::stos(args[1]);
    try {
        noct::Server server(port);
        server.start();
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
