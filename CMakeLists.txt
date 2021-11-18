cmake_minimum_required(VERSION 3.20)
project(stmpfs_rewrite)

set(EXTERNAL_LIBRARIES "")

set(CMAKE_CXX_STANDARD 20)

include(modules/func_def.cmake)

if ("X${CMAKE_BUILD_TYPE}" STREQUAL "XDebug")
    add_compile_definitions(CMAKE_BUILD_DEBUG=1)
endif()

add_compile_definitions("_FILE_OFFSET_BITS=64")
add_compile_definitions("PACKAGE_NAME=\"msgmap\"")
add_compile_definitions("PACKAGE_VERSION=\"0.0.1\"")

# default definitions
default_definition(MSGMAP_PREFIX "\"(stmpfs) \"")

# add external library
#set(SHA256SUM_SRC_FILES "")
#set(SHA256SUM_SRC_FILE_NO_PREFIX sha256sum.cpp)
#generate_ext_lib_files(${SHA256SUM_SRC_FILE_NO_PREFIX}
#        sha256sum SHA256SUM_SRC_FILES)
#add_ext_lib(sha256sum ${SHA256SUM_SRC_FILES})

# STEMPFS Static Library
add_library(msgmap
        src/msgmap_error.cpp    src/include/msgmap_error.h
        src/debug.cpp           src/include/debug.h
        )
target_include_directories(msgmap PUBLIC src/include)
target_link_libraries(msgmap PUBLIC ${EXTERNAL_LIBRARIES})

# Unit tests
if ("X${CMAKE_BUILD_TYPE}" STREQUAL "XDebug")
    stmpfs_add_test(error       "Error test")
    stmpfs_add_test(debug       "Debug test")
endif()
