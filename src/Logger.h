#pragma once

#include <string>
#include <mutex>

namespace noct {

class Logger {
    std::string filename_;
    std::mutex mtx_;

public:
    explicit Logger(std::string filename = "log.txt")
            :filename_(std::move(filename)) { }

    void log(const std::string& message);
};

} // namespace noct
