@echo off
cd /d %~dp0

echo [1/3] Stopping old process...
taskkill /f /im demo_avl.exe >nul 2>&1
timeout /t 1 /nobreak >nul
del demo_avl.exe >nul 2>&1

echo [2/3] Compiling...
g++ -I. -IAVLTree -o demo_avl.exe demo_avl.cpp AVLTree\insert.cpp AVLTree\delete.cpp AVLTree\search.cpp AVLTree\range.cpp AVLTree\range_s.cpp AVLTree\tree.cpp
if %errorlevel% neq 0 (
    echo [FAIL] Compilation failed!
    pause
    exit /b 1
)

echo [3/3] Build OK, starting...
echo.
.\demo_avl.exe
