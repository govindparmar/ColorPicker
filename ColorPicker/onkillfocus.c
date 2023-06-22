#include "CP.h"

VOID WINAPI OnKillFocus(_In_ HWND hWnd, _In_ HWND hWndNewFocus)
{
	ReleaseDC(NULL, g_hDesktopDC);
	g_hDesktopDC = NULL;
	ReleaseDC(hWnd, g_hWinDC);
	g_hWinDC = NULL;
	KillTimer(hWnd, IDT_TIMER1);
}