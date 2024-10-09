cmake_minimum_required(VERSION 3.29)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

# 檢查編譯器是否支持覆蓋率選項
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

# 添加 googletest 子目錄
add_subdirectory(googletest)

# 包含 googletest 的頭文件
include_directories(${PROJECT_SOURCE_DIR}/googletest/include)

add_executable(untitled2 main.cpp test.cpp
        main.h)

target_link_libraries(untitled2 gtest gtest_main)

enable_testing()
add_test(NAME untitled2 COMMAND untitled2)