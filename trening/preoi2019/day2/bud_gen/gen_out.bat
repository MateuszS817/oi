set str=Helloworld 
echo %str% 

set str=%str:~0,5% 
echo %str%

for /f %%f in ('dir /b in\  ') do (
	bud_naiw.exe < in\%%f > out\%%f
) 