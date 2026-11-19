cmake_minimum_required(VERSION 3.20)

project(nstd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(nstd INTERFACE)
target_include_directories(nstd INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.16.1
)
FetchContent_MakeAvailable(Catch2)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)

add_executable(nstd_tests ${TEST_SOURCES})
target_link_libraries(nstd_tests PRIVATE nstd Catch2::Catch2WithMain)

