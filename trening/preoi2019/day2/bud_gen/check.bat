set str=Helloworld 
echo %str% 

set str=%str:~0,5% 
echo %str%

for /f %%f in ('dir /b in\  ') do (
	chk.exe  in\%%f out\%%f out_mati\%%f >> res.txt
) 