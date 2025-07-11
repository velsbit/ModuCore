cmake_minimum_required(VERSION 3.10)
project(ModuCore C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(core src/main.c)

if(WIN32)
    target_link_libraries(core PRIVATE)
else()
    target_link_libraries(core PRIVATE dl)
endif()

add_subdirectory(plugins/plugin_sample)

set_target_properties(plugin_sample PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)