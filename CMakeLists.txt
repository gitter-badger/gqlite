cmake_minimum_required(VERSION 3.0)

project(GQLlite)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include ./libmdbx ./PEGTL/include)

aux_source_directory(src BASE_SOURCES)
aux_source_directory(src/QueryEngine QueryEngine_SOURCES)
aux_source_directory(src/StorageEngine StorageEngine_SOURCES)
aux_source_directory(src/Type Type_SOURCES)

message(${BASE_SOURCES})
add_library(gqlite ${BASE_SOURCES} ${QueryEngine_SOURCES} ${StorageEngine_SOURCES} ${Type_SOURCES})

add_subdirectory(test)