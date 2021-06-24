cmake_minimum_required(VERSION 3.0)
project(GQLlite_Test)

set(CMAKE_CXX_STANDARD 14)

include_directories(../include)

set(TEST_GRAMMAR_SOURCE ./grammar.cpp)

# link_libraries(gqlite)
add_executable(grammar ${TEST_GRAMMAR_SOURCE})

target_link_libraries(grammar PUBLIC gqlite)