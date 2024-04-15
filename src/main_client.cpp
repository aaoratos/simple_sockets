#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

#include "Client.h"
#include "Utility.h"

static void print_usage(const char* binary_path)
{
    std::cout << binary_path << ": "
              << "<client_name> " << "<server_port> "
              << "<connection_period>" << std::endl;
}

int main([[maybe_unused]] const int argc, [[maybe_unused]] const char* const* const argv)
{
    const std::vector<std::string> args(argv, std::next(argv, static_cast<std::ptrdiff_t>(argc)));
    if (args.size()!=4) {
        print_usage(args[0].c_str());
        return EXIT_FAILURE;
    }
    const std::string& client_name = args[1];
    const std::uint16_t server_port = noct::util::stos(args[2]);
    const std::uint32_t connection_period = noct::util::stos(args[3]);

    try {
        const noct::Client client("127.0.0.1", server_port);
        while (true) {
            std::string msg = "["+noct::util::get_timestamp()+"] "+client_name;
            client.send_message(msg);
            sleep(connection_period);
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}