#pragma once

#include <netinet/in.h>

#include "ThreadPool.h"
#include "Logger.h"
#include "Socket.h"

namespace noct {
class Server {
    std::unique_ptr<Socket> server_socket_;
    sockaddr_in server_addr_{};
    ThreadPool thread_pool_;
    Logger logger_;

public:
    explicit Server(std::uint16_t port);

    [[noreturn]] void start();
};

} // namespace noct