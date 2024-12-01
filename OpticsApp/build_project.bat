@echo off
setlocal enabledelayedexpansion

REM Define the project and build directories
set "PROJECT_DIR=%~dp0"
set "BUILD_DIR=%PROJECT_DIR%\build"

REM Check if the build directory exists, if not, create it
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

REM Navigate to the build directory
cd "%BUILD_DIR%"

REM Initialize SRC_FILES variable to hold all source file paths
set "SRC_FILES="

REM Find all .cpp files in the project directory and append them to SRC_FILES
for /r "%PROJECT_DIR%" %%i in (*.cpp) do (
    set "SRC_FILES=!SRC_FILES! "%%i""
)

REM Define the output binary name
set "OUTPUT_BINARY=optics_app.exe"

REM Compile the source files, including the directory for header files
echo Compiling the project...
g++ -o "%OUTPUT_BINARY%" %SRC_FILES% -Wall -Wextra -O2 -I"%PROJECT_DIR%\inc"

REM Check if compilation was successful
if %ERRORLEVEL% equ 0 (
    echo Build successful! Executable: %BUILD_DIR%\%OUTPUT_BINARY%
) else (
    echo Build failed.
    pause
    exit /b 1
)

REM Navigate back to the project directory
cd "%PROJECT_DIR%"

REM Pause to show the user that the build has completed
pause
