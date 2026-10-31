@echo off
setlocal
pushd "%~dp0.."
if not exist "build\tests\training_main.exe" (
    echo training_main.exe does not exist. Run script\build.bat first.
    popd
    exit /b 1
)
build\tests\training_main.exe %*
set "testResult=%errorlevel%"
popd
exit /b %testResult%
