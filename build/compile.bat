@echo off && setlocal enabledelayedexpansion 
cd .. 
@echo Generating executable file... 
FOR /f "delims=" %%a IN ('dir /a:d-r-h-a-s /s /b') DO SET includes=^!includes^! -I%%a 
 
FOR /f "delims=" %%g IN ('dir /s /b ^| findstr /e ".cpp" ') DO SET files=^!files^! %%g 

IF "%1" == "--debug" ( 
  g++ -g %files% %includes% -o ./app/main.exe -std=gnu++17 && @echo Successfully generated debug executable file^!
  GOTO :end 
 
) 
 
IF "%1" == "--optimize" ( 
  g++ -Ofast %files% %includes% -o ./app/main.exe -std=gnu++17 && @echo Successfully generated optimized executable file^!
  GOTO :end 
) 
 
g++ %files% %includes% -o ./app/main.exe -std=gnu++17 && @echo Successfully generated executable file^!
:end 
