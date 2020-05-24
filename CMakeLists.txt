# Initialize Cmake
cmake_minimum_required(VERSION 3.16)
# If current cmake is not available, call the cmake.
if(${CMAKE_VERSION} VERSION_LESS 3.16)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}) # used to set policies to new behaviour.
else()
    cmake_policy(VERSION 3.16)
endif()


# Setup the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(CudaOfLife VERSION 0.0.1 LANGUAGES CUDA CXX)
add_executable(${PROJECT_NAME} src/main.cu)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL)
find_package(GLUT REQUIRED)
target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARY})

add_library(utils src/u.cpp src/u.hpp)
target_link_libraries(${PROJECT_NAME} utils)

