#ifndef MOTD_INFO_HPP
#define MOTD_INFO_HPP


#include <string>

namespace motd {
struct info {
    std::string sysName;
    std::string nodeName;
    std::string kernelRelease;
    std::string kernelVersion;
    std::string machine;
    std::string domainName;
};
}
#endif
