#include <windows.h>
#include <stdio.h>
#include <process.h>

unsigned Counter = 0;

unsigned __stdcall SecondThreadFunc( void* pArguments )
{
    while(1)
    {
    	Sleep(6000); //每隔6秒执行一次累加!
    	Counter ++;	
    	printf( "Counter is-> %d\n", Counter );
    }
} 

int main()
{ 
    int c;
	HANDLE hThread;
    unsigned threadID;

    printf( "Creating second thread...\n" );

    // Create the second thread.
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc, NULL, 0, &threadID );

    //只是为了防止主线程退出!
    WaitForSingleObject( hThread, INFINITE);
	
	while ((c = getchar()) != 0)
		putchar(c);
    
    CloseHandle( hThread );
}
