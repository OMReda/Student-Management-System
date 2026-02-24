@echo off
REM Check if compiled executable exists
if not exist sms.exe (
    echo Compiling Student Management System...
    g++ -o sms.exe main.cpp
    if %errorlevel% neq 0 (
        echo Compilation failed!
        pause
        exit /b %errorlevel%
    )
)

REM Run the application
echo Starting Student Management System...
.\sms.exe
pause
