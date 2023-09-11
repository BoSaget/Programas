@echo off
setlocal enabledelayedexpansion

REM Input values (replace these with your own float values)
set "num1=3.14"
set "num2=2.5"

REM Use PowerShell to perform float calculations
for /f %%i in ('powershell "([float]!num1!) + ([float]!num2!)"') do set "sum=%%i"
for /f %%i in ('powershell "([float]!num1!) - ([float]!num2!)"') do set "difference=%%i"
for /f %%i in ('powershell "([float]!num1!) * ([float]!num2!)"') do set "product=%%i"

REM Display the results
echo Sum: %sum%
echo Difference: %difference%
echo Product: %product%

endlocal
