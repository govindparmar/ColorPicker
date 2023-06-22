#include "CP.h"

VOID WINAPI OnSetFocus(_In_ HWND hWnd, HWND hWndOldFocus)
{
	if (NULL == g_hDesktopDC)
	{
		g_hDesktopDC = GetDC(NULL);
	}
	
	if (NULL == g_hWinDC)
	{
		g_hWinDC = GetDC(hWnd);
	}

	SetTimer(hWnd, IDT_TIMER1, 10, TimerProc);
}
