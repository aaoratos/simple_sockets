#include "ThreadPool.h"

namespace noct {

void ThreadPool::start(const std::function<void()>& func)
{
    workers_.emplace_back(func);
}

ThreadPool::~ThreadPool()
{
    for (auto& worker : workers_) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

} // namespace noct
