cmake_minimum_required(VERSION 3.21)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/Users/nickn/Documents/SDL2-2.24.0/include)
set(SDL2_LIB_DIR C:/Users/nickn/Documents/SDL2-2.24.0/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

MATH(EXPR stack_size "1000 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(minesweeper main.cpp singular_box.cpp singular_box.h funcs.h table_box.cpp table_box.h toolbox.cpp toolbox.h popup.cpp popup.h slidebar.cpp slidebar.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_ttf SDL2_image)