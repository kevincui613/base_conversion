@echo off
REM Windows batch script for compiling the base conversion project
REM This script is for Windows with MinGW installed

setlocal enabledelayedexpansion

echo.
echo ====== Base Conversion Build System ======
echo.

REM Check if gcc is available
where gcc >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Error: gcc not found. Please install MinGW.
    echo Visit: https://www.mingw-w64.org/
    pause
    exit /b 1
)

REM Create directories
if not exist obj mkdir obj
if not exist bin mkdir bin

echo [*] Compiling converter.c...
gcc -Wall -Wextra -g -O2 -Iinclude -c src/converter.c -o obj/converter.o
if %ERRORLEVEL% NEQ 0 (
    echo Error: Failed to compile converter.c
    pause
    exit /b 1
)
echo [OK] converter.o generated

echo [*] Compiling main.c...
gcc -Wall -Wextra -g -O2 -Iinclude -c src/main.c -o obj/main.o
if %ERRORLEVEL% NEQ 0 (
    echo Error: Failed to compile main.c
    pause
    exit /b 1
)
echo [OK] main.o generated

echo [*] Linking...
gcc -Wall -Wextra -g -O2 -o bin/converter.exe obj/converter.o obj/main.o
if %ERRORLEVEL% NEQ 0 (
    echo Error: Failed to link
    pause
    exit /b 1
)
echo [OK] converter.exe generated

echo.
echo ====== Build Complete ======
echo.
echo To run the program, execute:
echo   bin\converter.exe
echo.

REM Ask to run the program
set /p run="Do you want to run the program now? (y/n): "
if /i "%run%"=="y" (
    bin\converter.exe
)

pause
