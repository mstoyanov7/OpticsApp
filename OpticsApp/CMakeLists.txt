cmake_minimum_required(VERSION 3.20)

# Set the project name
project(OpticsApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the output solution format for Visual Studio 2022
set(CMAKE_GENERATOR "Visual Studio 17 2022")

# Specify the directories where the header files and source files are located
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Glob the source files in the src folder
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Glob the header files in the inc folder and explicitly add them to the project
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/inc/*.h)

# Group headers and sources for IDEs like Visual Studio
source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Optionally specify warnings for MSVC
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
endif()
