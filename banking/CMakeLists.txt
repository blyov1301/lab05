cmake_minimum_required(VERSION 3.16)
project(banking LANGUAGES CXX)

add_library(banking STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Account.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Transaction.cpp
)

target_include_directories(banking PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(banking PUBLIC cxx_std_11)
