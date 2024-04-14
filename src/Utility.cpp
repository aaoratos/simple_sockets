#include "Utility.h"

#include <chrono>
#include <sstream>
#include <iomanip>

namespace noct::util {

/**
 * Get string representation of the current date and time
 * in the format "yyyy-mm-dd hh:mm:ss.ms"
 *
 * @return Timestamp string
 */
std::string get_timestamp()
{
    using namespace std::chrono;

    const time_point now_tp = system_clock::now();
    const time_t now_c = system_clock::to_time_t(now_tp);
    const time_point ms = time_point_cast<milliseconds>(now_tp);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%F %T.");
    ss << ms.time_since_epoch().count()%1000;

    return ss.str();
}

/**
 * Convert string to uint16_t
 *
 * @param str String to covert
 * @return uint16_t number
 */
std::uint16_t stos(const std::string& str)
{
    int si = std::stoi(str);
    if (std::numeric_limits<std::uint16_t>::min()<=si && si<=std::numeric_limits<std::uint16_t>::max()) {
        return static_cast<std::uint16_t>(si);
    }
    throw std::range_error("Argument is out of range");
}

} // namespace noct::util
