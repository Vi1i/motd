set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

add_executable(motd-cli
    src/main.cpp
)

target_link_libraries(motd-cli 
    MotdCore
    ${CMAKE_DL_LIBS}
    stdc++fs
)

install(TARGETS motd-cli
  EXPORT MotdCoreTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
