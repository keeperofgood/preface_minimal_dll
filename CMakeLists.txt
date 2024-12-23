cmake_minimum_required(VERSION 3.29)


project(ecs_test_sys LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ecs_test_sys SHARED minimal_dll_loader.cpp version.rc)


if(MSVC)
    target_compile_options(ecs_test_sys PRIVATE /W4)
else()
    target_compile_options(ecs_test_sys PRIVATE -Wall -Wextra -pedantic)
endif()

set_target_properties(ecs_test_sys PROPERTIES
        OUTPUT_NAME "ecs_test_sys"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>
)
