#pragma once

#include <sys/socket.h>

struct sockaddr_in;

namespace noct {

class Socket {
public:
    Socket()
            :sockfd_(socket(AF_INET, SOCK_STREAM, 0)) { }

    explicit Socket(int domain, int type, int protocol);

    void bind(const sockaddr_in& addr) const;

    void listen(int backlog) const;

    [[nodiscard]] int accept(sockaddr_in& addr) const;

    ~Socket();

    [[nodiscard]] int get_fd() const { return sockfd_; }

    explicit operator int() const { return sockfd_; }

private:
    int sockfd_;
};

} // namespace noct
