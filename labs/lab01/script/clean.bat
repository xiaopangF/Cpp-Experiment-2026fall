@echo off
setlocal
pushd "%~dp0.."
if not exist "build\CMakeCache.txt" (
    popd
    exit /b 0
)
cmake --build build --target clean
set "cleanResult=%errorlevel%"
popd
exit /b %cleanResult%
