@echo off

REM This script builds a project based on a given CMakeLists.txt file

REM Define the directory where the CMakeLists.txt file is located
set "PROJECT_DIR=%~dp0"

REM Define the directory where the build files will be generated
set "BUILD_DIR=%PROJECT_DIR%\build"

REM Check if the build directory exists, if not, create it
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

REM Navigate to the build directory
cd "%BUILD_DIR%"

REM Run cmake to generate the project files
cmake -G "Visual Studio 17 2022" "%PROJECT_DIR%"

REM Run cmake to build the project
cmake --build . --config Release

REM Navigate back to the project directory
cd "%PROJECT_DIR%"

REM Pause to show the user that the build has completed
pause
