@echo off
rem Just run the python script
REM python C:\ACM\tools\cxxtest-4.4\bin\cxxtestgen %*
REM set pyname = %0
REM if /i %pyname:~-4%==.bat (
	REM echo yes
	REM set str2 = %pyname:~0,-4%
	REM python %str2% %*
REM ) else (
	REM echo no
	REM python %0 %*
REM )
python %0 %*