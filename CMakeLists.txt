cmake_minimum_required(VERSION 3.0)

project(GQLlite)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include)

aux_source_directory(src ALL_SOURCES)

add_library(gqlite ${ALL_SOURCES})