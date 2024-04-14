#include "Logger.h"

#include <fstream>

namespace noct {

void Logger::log(const std::string& message)
{
    std::lock_guard<std::mutex> lock(mtx_);
    std::ofstream ofs(filename_, std::ios_base::app);
    ofs << message << std::endl;
}

} // namespace noct
