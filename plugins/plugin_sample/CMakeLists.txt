add_library(plugin_sample SHARED plugin.c)

target_compile_definitions(plugin_sample PRIVATE EXPORTING_PLUGIN)

target_include_directories(plugin_sample PRIVATE ${CMAKE_SOURCE_DIR}/include)