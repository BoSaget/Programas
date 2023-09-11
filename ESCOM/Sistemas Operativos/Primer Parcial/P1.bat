:: Programa hecho por: Leon Francisco Tejeda Moyao
:: Sistemas Operativos Grupo 4CV2
:: Practica 1: "Máximo, Minimo y Promedio"
@echo off
setlocal enabledelayedexpansion

REM Define the array of numbers
set "numbers=1 9 10 10 10 10 10"

REM Initialize variables for min, max, and sum
set "min="
set "max="
set "sum=0"
set "count=0"

REM Split the numbers into an array
for %%i in (%numbers%) do (
    set "number=%%i"
    
    REM Update minimum and maximum values
    if not defined min (set "min=!number!") else if !number! lss !min! set "min=!number!"
    if not defined max (set "max=!number!") else if !number! gtr !max! set "max=!number!"
    
    REM Calculate the sum and count
    set /a "sum+=number"
    set /a "count+=1"
)

REM Calculate the average
set /a "average=sum / count"

REM Display the results
echo Minimum: %min%
echo Maximum: %max%
echo Average: %average%

endlocal
