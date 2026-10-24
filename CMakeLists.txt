cmake_minimum_required(VERSION 3.16)

project(Oathwyn LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(SDL3 REQUIRED CONFIG)

add_executable(oathwyn
    src/main.c
)

target_link_libraries(oathwyn
    PRIVATE SDL3::SDL3
)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(oathwyn PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()