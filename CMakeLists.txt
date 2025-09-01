cmake_minimum_required(VERSION 3.16)
project(pdi_code)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/app/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
