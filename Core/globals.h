#include <string_view>

namespace Core{
#ifdef __LINUX__
    static const std::string_view ENDOFLINE = "\r\n";
#else
    static const std::string_view ENDOFLINE = "\n";
#endif
}
