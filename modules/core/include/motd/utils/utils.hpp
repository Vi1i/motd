#ifndef MOTD_UTILS_HPP
#define MOTD_UTILS_HPP

#include <motd/settings.hpp>
#include <motd/info.hpp>

#include <string>
#include <memory>

namespace motd { namespace utils {
    motd::settings OptParse(int argc, char * argv[]);
    int GetSystemInfo(std::shared_ptr<motd::info> info);
    //TODO: (Vi1i) Look into "/etc/os-release" and "/usr/lib/os-release" for OS Name
    int WriteMotd(std::string filename);
}}
#endif
