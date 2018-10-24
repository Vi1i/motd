set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(libconfig++ REQUIRED)
find_package(spdlog REQUIRED)

CHECK_INCLUDE_FILE_CXX_ERROR("sys/utsname.h" HAVE_SYS_UTSNAME)
CHECK_INCLUDE_FILE_CXX_ERROR("errno.h" HAVE_ERRNO)

add_library(MotdCore SHARED
    src/motd.cpp
    src/utils.cpp
)

target_link_libraries(MotdCore
    stdc++fs
    ${LIBCONFIG++_LIBRARIES}
)

target_include_directories(MotdCore
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(MotdCore PROPERTIES
    VERSION 0.1.0
    SOVERSION 0
)

install(DIRECTORY include/ DESTINATION "${INSTALL_INCLUDE_DIR}")

install(TARGETS MotdCore
    EXPORT MotdCoreTargets
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
    LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
)
