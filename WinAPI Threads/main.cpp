#include <windows.h>
#include <stdio.h>

using namespace std;

#define MAX_SEM_THREAD_COUNT	1
#define THREAD_INIT_COUNT		1
#define INTERATION_COUNT		10
#define SLEEPING_TIME			1


HANDLE ghMutex;
HANDLE ghSemaphore;
HANDLE Resume_All;

HANDLE A_Thread; DWORD A_ThreadID;
HANDLE B_Thread; DWORD B_ThreadID;
HANDLE C_Thread; DWORD C_ThreadID;
HANDLE D_Thread; DWORD D_ThreadID;
HANDLE E_Thread; DWORD E_ThreadID;
HANDLE F_Thread; DWORD F_ThreadID;
HANDLE G_Thread; DWORD G_ThreadID;
HANDLE H_Thread; DWORD H_ThreadID;
HANDLE P_Thread; DWORD P_ThreadID;
HANDLE K_Thread; DWORD K_ThreadID;
HANDLE M_Thread; DWORD M_ThreadID;
HANDLE N_Thread; DWORD N_ThreadID;

HANDLE All_Threads[] = {
	A_Thread, 
	B_Thread, 
	C_Thread, 
	D_Thread,
	E_Thread,
	F_Thread,
	G_Thread,
	H_Thread,
	P_Thread,
	K_Thread,
	M_Thread,
	N_Thread
};

bool create_thread(HANDLE &Thread, LPTHREAD_START_ROUTINE ThreadFunction, DWORD &ThreadID)
{
    Thread = CreateThread(
                    NULL,       // default security attributes
                    0,          // default stack size
                    ThreadFunction,
                    NULL,       // no thread function arguments
                    0,          // default creation flags
                    &ThreadID); // receive thread identifier
	SuspendThread(Thread);
    if(Thread == NULL )
    {
        printf("CreateThread error: %d\n", GetLastError());
        return false;
    }
	return true;
}

DWORD WINAPI A_func()
{
	for(int i = 0; i < INTERATION_COUNT; i++)
	{
		printf("A");
		Sleep(SLEEPING_TIME);
	}
	return TRUE;
}

DWORD WINAPI B_func()
{
	for(int i = 0; i < INTERATION_COUNT + 5; i++)
	{
		printf("B");
		Sleep(SLEEPING_TIME);
	}
	return TRUE;
}

DWORD WINAPI C_func()
{
	WaitForSingleObject(A_Thread, INFINITE);
	HANDLE temp_handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"test_mutex");
	for(int i = 0; i < INTERATION_COUNT + 5; i++)
	{
		WaitForSingleObject(temp_handle, INFINITE);
		printf("C");
		Sleep(SLEEPING_TIME);
		ReleaseMutex(temp_handle);
	}
	return TRUE;
}

DWORD WINAPI D_func()
{
	WaitForSingleObject(G_Thread, INFINITE);
	HANDLE temp_handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"test_mutex");
	for(int i = 0; i < INTERATION_COUNT; i++)
	{
		WaitForSingleObject(temp_handle, INFINITE);
		printf("D");
		Sleep(SLEEPING_TIME);
		ReleaseMutex(temp_handle);
	}
	return TRUE;
}

DWORD WINAPI E_func()
{
	WaitForSingleObject(B_Thread, INFINITE);
    HANDLE temp_handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"test_mutex");
	for(int i = 0; i < 2 * INTERATION_COUNT; i++)
	{
		WaitForSingleObject(temp_handle, INFINITE);
		printf("E");
		Sleep(SLEEPING_TIME);
		ReleaseMutex(temp_handle);
	}
	return TRUE;
}

DWORD WINAPI F_func()
{
	WaitForSingleObject(C_Thread, INFINITE);
	for(int i = 0; i < 2 * INTERATION_COUNT; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("F");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}

DWORD WINAPI G_func()
{
	WaitForSingleObject(E_Thread, INFINITE);
    
	for(int i = 0; i < INTERATION_COUNT + 5; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("G");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}

DWORD WINAPI H_func()
{
	WaitForSingleObject(G_Thread, INFINITE);
    
	for(int i = 0; i < INTERATION_COUNT / 2.0 + 2; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("H");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}

DWORD WINAPI P_func()
{
	WaitForSingleObject(G_Thread, INFINITE);

	for(int i = 0; i < INTERATION_COUNT - 5; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("P");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}

DWORD WINAPI K_func()
{
	WaitForSingleObject(H_Thread, INFINITE);
	WaitForSingleObject(F_Thread, INFINITE);
    for(int i = 0; i < INTERATION_COUNT; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("K");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}

DWORD WINAPI M_func()
{
	WaitForSingleObject(H_Thread, INFINITE);
	WaitForSingleObject(F_Thread, INFINITE);
    HANDLE temp_handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"test_mutex");
	for(int i = 0; i < 3 * INTERATION_COUNT; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("M");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}

DWORD WINAPI N_func()
{
	WaitForSingleObject(P_Thread, INFINITE);
	WaitForSingleObject(K_Thread, INFINITE);
	HANDLE temp_handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"test_mutex");
	for(int i = 0; i < 2 * INTERATION_COUNT; i++)
	{
		WaitForSingleObject(ghSemaphore, INFINITE);
		printf("N");
		Sleep(SLEEPING_TIME);
		ReleaseSemaphore(ghSemaphore, 1, NULL);
	}
	return TRUE;
}
/*
 * not sync: A, B
 * sync by mutex: C, D, E
 * sync by semaphore: F, G, H, P, K, M, N
 */

CRITICAL_SECTION crit_sec;


int main()
{
	// =========================================================================
	ghMutex = CreateMutex(
		NULL,					// default security attributes
        FALSE,					// initially not owned
        L"test_mutex"			// name of mutex
	);	

	Resume_All = CreateMutex(
		NULL,					// default security attributes
		FALSE,					// initially not owned
		L"pause"			// name of mutex
	);

	ghSemaphore = CreateSemaphore(
        NULL,					// default security attributes
        THREAD_INIT_COUNT,		// initial count
        MAX_SEM_THREAD_COUNT,	// maximum count
        L"test_semaphore"		// unnamed semaphore
	);
	// =========================================================================
	create_thread(A_Thread, (LPTHREAD_START_ROUTINE) A_func, A_ThreadID);
	create_thread(B_Thread, (LPTHREAD_START_ROUTINE) B_func, B_ThreadID);
	create_thread(C_Thread, (LPTHREAD_START_ROUTINE) C_func, C_ThreadID);
	create_thread(D_Thread, (LPTHREAD_START_ROUTINE) D_func, D_ThreadID);
	create_thread(E_Thread, (LPTHREAD_START_ROUTINE) E_func, E_ThreadID);
	create_thread(F_Thread, (LPTHREAD_START_ROUTINE) F_func, F_ThreadID);
	create_thread(G_Thread, (LPTHREAD_START_ROUTINE) G_func, G_ThreadID);
	create_thread(H_Thread, (LPTHREAD_START_ROUTINE) H_func, H_ThreadID);
	create_thread(P_Thread, (LPTHREAD_START_ROUTINE) P_func, P_ThreadID);
	create_thread(K_Thread, (LPTHREAD_START_ROUTINE) K_func, K_ThreadID);
	create_thread(M_Thread, (LPTHREAD_START_ROUTINE) M_func, M_ThreadID);
	create_thread(N_Thread, (LPTHREAD_START_ROUTINE) N_func, H_ThreadID);

	
	ResumeThread(A_Thread);
	ResumeThread(B_Thread);
	ResumeThread(C_Thread);
	ResumeThread(D_Thread);
	ResumeThread(E_Thread);
	ResumeThread(F_Thread);
	ResumeThread(G_Thread);
	ResumeThread(H_Thread);
	ResumeThread(P_Thread);
	ResumeThread(K_Thread);
	ResumeThread(M_Thread);
	ResumeThread(N_Thread);
	// =========================================================================
	WaitForSingleObject(N_Thread, INFINITE);
	WaitForSingleObject(M_Thread, INFINITE);
	// =========================================================================
	CloseHandle(A_Thread);
	CloseHandle(B_Thread);
	CloseHandle(C_Thread);
	CloseHandle(D_Thread);
	CloseHandle(E_Thread);
	CloseHandle(F_Thread);
	CloseHandle(G_Thread);
	CloseHandle(H_Thread);
	CloseHandle(P_Thread);
	CloseHandle(K_Thread);
	CloseHandle(M_Thread);
	CloseHandle(N_Thread);

	CloseHandle(ghSemaphore);
	CloseHandle(ghMutex);
	// =========================================================================
	printf("\n\n");
	system("pause");
    return 0;
}