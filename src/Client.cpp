#include "Client.h"
#include "Socket.h"

#include <stdexcept>

namespace noct {

[[maybe_unused]] Client::Client(const std::string& hostname, std::uint16_t port)
{
    client_socket_ = std::make_unique<noct::Socket>();
    server_addr_.sin_family = AF_INET;
    server_addr_.sin_port = htons(port);
    server_addr_.sin_addr.s_addr = inet_addr(hostname.c_str());

    if (connect(static_cast<int>(*client_socket_),
            (struct sockaddr*) &server_addr_,
            sizeof(server_addr_))<0) {
        throw std::runtime_error("Connection failed");
    }
}

void Client::send_message(const std::string& message) const
{
    send(static_cast<int>(*client_socket_), message.c_str(), message.length(), 0);
}

} // namespace noct
