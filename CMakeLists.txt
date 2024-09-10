cmake_minimum_required(VERSION 3.16)

project(mc LANGUAGES C VERSION 0.1)
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(ZLIB REQUIRED)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type (default is Release)" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address,undefined")
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.c)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h)

add_executable(mc ${SRC_FILES} ${HEADER_FILES})
target_link_libraries(mc PRIVATE z glfw GLFW:gl)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(mc PRIVATE -fsanitize=address,undefined)
    target_link_libraries(mc PRIVATE -fsanitize=address,undefined)
endif()

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include/mc)
