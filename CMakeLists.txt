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

# Link files
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp" "src/*.cu")
file(GLOB_RECURSE PROJECT_HEADERS "src/*.h")
set (PROJECT_INCLUDE_DIRS "")
foreach (_headerFile ${PROJECT_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND PROJECT_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Foo_INCLUDE_DIRS})

# Link dependencies
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL)
find_package(GLU REQUIRED)
target_link_libraries(${PROJECT_NAME} ${GLU_LIBRARY})
find_package(GLUT REQUIRED)
target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARY})