#include <motd/utils/utils.hpp>
#include <motd/motd.hpp>
#include <motd/info.hpp>

#include <cstdlib>
#include <memory>

int main(int argc, char * argv[]) {
    std::shared_ptr<motd::info> info(new motd::info);

    motd::utils::OptParse(argc, argv);
    motd::utils::GetSystemInfo(info);

    return EXIT_SUCCESS;
}
