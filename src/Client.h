#pragma once

#include <string>
#include <memory>
#include <arpa/inet.h>

#include "Socket.h"

namespace noct {

class Client {
    std::unique_ptr<Socket> client_socket_;
    sockaddr_in server_addr_{};

public:
    [[maybe_unused]] explicit Client(const std::string& hostname, std::uint16_t port);

    void send_message(const std::string& message) const;
};

} // namespace noct
