@ECHO OFF
ECHO Generating Documentation...
:: Set the Doxygen Path here
SET DOXYGEN_PATH="C:\Program Files\doxygen\bin"

:: Effectively calling doxygen and executing the Doxyfile in the current folder
call %DOXYGEN_PATH%\doxygen.exe Doxyfile
PAUSE