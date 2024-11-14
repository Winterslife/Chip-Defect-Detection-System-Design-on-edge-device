cmake_minimum_required(VERSION 3.15)

include(proj.conf)

find_package(bouffalo_sdk REQUIRED HINTS $ENV{BL_SDK_BASE})


# User
sdk_add_compile_definitions(-DCONFIG_CLI_CMD_ENABLE)

file(GLOB_RECURSE src_c "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
target_sources(app PRIVATE ${src_c})

sdk_add_include_directories(.)
sdk_add_include_directories(inc)
sdk_add_include_directories(inc/tinymaix)

sdk_set_main_file(main.c)

project(lvgl_wifi)
