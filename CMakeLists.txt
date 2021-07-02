cmake_minimum_required(VERSION 3.0)

project(GQLlite)

set(CMAKE_CXX_STANDARD 14)
IF (WIN32)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
ELSEIF (APPLE)
ELSEIF (UNIX)
ELSE ()
ENDIF ()

include_directories(./include ./libmdbx ./PEGTL/include)

aux_source_directory(src BASE_SOURCES)
aux_source_directory(src/QueryEngine QueryEngine_SOURCES)
aux_source_directory(src/StorageEngine StorageEngine_SOURCES)
aux_source_directory(src/Type Type_SOURCES)
add_subdirectory(libmdbx)

message(${BASE_SOURCES})
add_library(gqlite ${BASE_SOURCES} ${QueryEngine_SOURCES} ${StorageEngine_SOURCES} ${Type_SOURCES})
target_link_libraries(gqlite mdbx-static)

add_subdirectory(test)