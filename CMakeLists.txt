cmake_minimum_required(VERSION 3.0.0)
project(ASCII_Runner)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

enable_testing()

set (INCLUDE_DIRS "")
foreach (_header_file ${HEADERS})
    get_filename_component(_dir ${_header_file} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
target_link_libraries( ${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image::SDL2_image )
