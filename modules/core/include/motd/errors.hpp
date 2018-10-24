#ifndef MOTD_ERRORS_HPP
#define MOTD_ERRORS_HPP

namespace motd {
    struct error {
        enum type {
            NO_ERROR,
            GENERAL,
            FILE_NOT_FOUND,
            SYSTEM_INFO,
            SHARED_PTR,
        };
    };
}
#endif
