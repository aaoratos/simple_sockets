#include "Socket.h"

#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace noct {

Socket::Socket(int domain, int type, int protocol)
{
    sockfd_ = socket(domain, type, protocol);
    if (sockfd_<0) {
        throw std::runtime_error("Unable to create socket");
    }
}

void Socket::bind(const sockaddr_in& addr) const
{
    if (::bind(sockfd_, reinterpret_cast<const struct sockaddr*>(&addr), sizeof(addr))<0) {
        throw std::runtime_error("Bind failed");
    }
}

void Socket::listen(int backlog) const
{
    if (::listen(sockfd_, backlog)<0) {
        throw std::runtime_error("Listen failed");
    }
}

int Socket::accept(sockaddr_in& addr) const
{
    socklen_t addr_len = sizeof(addr);
    int new_sock = ::accept(sockfd_, reinterpret_cast<struct sockaddr*>(&addr), &addr_len);
    if (new_sock<0) {
        throw std::runtime_error("Accept failed");
    }
    return new_sock;
}

Socket::~Socket()
{
    close(sockfd_);
}

} // namespace noct
