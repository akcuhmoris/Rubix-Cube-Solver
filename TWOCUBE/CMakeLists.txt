cmake_minimum_required(VERSION 3.5.0)
project(TWOCUBE VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

# List all source files explicitly
add_executable(TWOCUBE 
    main.cpp 
    TwoCube.cpp 
    # Add more source files as needed
)

# Include directories for header files
include_directories(include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
