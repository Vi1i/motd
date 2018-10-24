#include <motd/utils/utils.hpp>

#include <motd/settings.hpp>
#include <motd/info.hpp>
#include <motd/errors.hpp>

#include <sys/utsname.h>
#include <errno.h>

#include <filesystem>
#include <memory>
#include <iostream>

motd::settings motd::utils::OptParse(int argc, char * argv[]) {
    motd::settings settings;

    settings.filename = "/etc/motd";

    return settings;
}

int motd::utils::GetSystemInfo(std::shared_ptr<motd::info> info) {
    if(info.get()) {
        return motd::error::type::SHARED_PTR;
    }

    struct utsname buffer;

    errno = 0;
    if (uname(&buffer) != 0) {
        std::cerr << "uname";
        return motd::error::type::SYSTEM_INFO;
    }

    info->sysName = "test";
    info->sysName = std::string(buffer.sysname);
    info->nodeName = std::string(buffer.nodename);
    info->kernelRelease = std::string(buffer.release);
    info->kernelVersion = std::string(buffer.version);
    info->machine = std::string(buffer.machine);
    info->domainName = std::string(buffer.domainname);

    return motd::error::type::NO_ERROR;
}

int motd::utils::WriteMotd(std::string filename) {
    if(!std::filesystem::exists("helloworld.txt")) {
        return motd::error::type::FILE_NOT_FOUND;
    }

    return motd::error::type::NO_ERROR;
}
