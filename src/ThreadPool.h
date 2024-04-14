#pragma once

#include <vector>
#include <thread>
#include <functional>

namespace noct {
class ThreadPool {
    std::vector<std::thread> workers_;
public:
    void start(const std::function<void()>& func);

    ~ThreadPool();
};

} // namespace noct