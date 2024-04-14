#include "Server.h"
#include "Utility.h"

noct::Server::Server(std::uint16_t port)
{
    server_socket_ = std::make_unique<Socket>();
    server_addr_.sin_family = AF_INET;
    server_addr_.sin_port = htons(port);
    server_addr_.sin_addr.s_addr = INADDR_ANY;

    server_socket_->bind(server_addr_);
    server_socket_->listen(5);
}

void noct::Server::start()
{
    while (true) {
        int client_socket = server_socket_->accept(server_addr_);
        thread_pool_.start([this, client_socket]() -> void {
          char client_message[1024];
          while (recv(client_socket, client_message, sizeof(client_message), 0)>0) {
              logger_.log(client_message);
          }
          close(client_socket);
        });
    }
}
