@echo off
set MSYSTEM=
set SHELL=
set IDF_PATH=C:\Espressif\frameworks\esp-idf-v5.5.4
set IDF_TOOLS_PATH=C:\Espressif
call C:\Espressif\frameworks\esp-idf-v5.5.4\export.bat >nul 2>&1
cd /d C:\Users\nawaznotnatty\gnarl-1\project
idf.py %* >C:\Users\nawaznotnatty\gnarl-1\scratch_idf.log 2>&1
echo IDF_EXIT=%errorlevel% >>C:\Users\nawaznotnatty\gnarl-1\scratch_idf.log
