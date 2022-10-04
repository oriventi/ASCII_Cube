@echo off 
SET debug=0 
SET optimize=0 
SET noCompile=0 
SET exit=0 
 
::Get optional parameters 
:loop 
IF "%1" == "--debug" ( 
  SET debug=1 
  SHIFT 
  GOTO :loop 
) 
IF "%1" == "--optimize" ( 
  SET optimize=1 
  SHIFT 
  GOTO :loop 
) 
IF "%1" == "--no-compile" ( 
  SET noCompile=1 
  SHIFT 
  GOTO :loop 
) 
 
IF "%1" == "--exit" ( 
  SET exit=1 
  SHIFT 
  GOTO :loop 
) 
 
SET /a "check=%debug%+%noCompile%+%optimize%" 
IF "%check%" gtr "1" ( 
  @echo [Error]: Du kannst entweder --optimize oder --debug oder --no-compile schreiben 
) 
 
IF %debug% == 1 (  
  call compile.bat --debug && ..\app\main.exe  
  GOTO :end  
)  
IF %optimize% == 1 (  
  call compile.bat --optimize && ..\app\main.exe  
  GOTO :end  
)  
 
IF %noCompile% == 1 (  
  ..\app\main.exe  
  GOTO :end  
)  
 
call compile.bat && ..\app\main.exe 
:end 
 
IF %exit% == 1 ( 
exit 
) 
