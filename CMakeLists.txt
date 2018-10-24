cmake_minimum_required(VERSION 3.9)
project(MotdCore)


set(MOTDCORE_MAJOR_VERSION 0)
set(MOTDCORE_MINOR_VERSION 1)
set(MOTDCORE_PATCH_VERSION 0)
set(MOTDCORE_VERSION
    ${MOTDCORE_MAJOR_VERSION}.${MOTDCORE_MINOR_VERSION}.${MOTDCORE_PATCH_VERSION})

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")

if(WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
else()
    set(DEF_INSTALL_CMAKE_DIR lib/CMake/MotdCore)
endif()

set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
    set(var INSTALL_${p}_DIR)
    if(NOT IS_ABSOLUTE "${${var}}")
        set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
    endif()
endforeach()

# set up include-directories
include_directories(
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_BINARY_DIR}")

include(cmake/macros.cmake)
# Add sub-directories
add_subdirectory(modules/core)
add_subdirectory(modules/cli)

# The interesting stuff goes here
# ===============================

# Add all targets to the build-tree export set
export(TARGETS MotdCore
    FILE "${PROJECT_BINARY_DIR}/MotdCoreTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE MotdCore)

# Create the MotdCoreConfig.cmake and MotdCoreConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
    "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(MotdCoreConfig.cmake.in
    "${PROJECT_BINARY_DIR}/MotdCoreConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${MOTDCORE_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(MotdCoreConfig.cmake.in
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MotdCoreConfig.cmake" @ONLY)
# ... for both
configure_file(MotdCoreConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/MotdCoreConfigVersion.cmake" @ONLY)

# Install the MotdCoreConfig.cmake and MotdCoreConfigVersion.cmake
install(FILES
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MotdCoreConfig.cmake"
    "${PROJECT_BINARY_DIR}/MotdCoreConfigVersion.cmake"
    DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT MotdCoreTargets DESTINATION
    "${INSTALL_CMAKE_DIR}" COMPONENT dev)

