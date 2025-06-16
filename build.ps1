# Compile hra.cpp using clang++
clang++ -std=c++17 -Wall -Wextra -o .\build\hra.exe .\src\hra.cpp
if ($LASTEXITCODE -eq 0) {
    Write-Host "Compilation successful. Run with: .\hra.exe"
} else {
    Write-Host "Compilation failed."
}