#include "CP.h"

VOID WINAPI OnKillFocus(_In_ HWND hWnd, _In_ HWND hWndNewFocus)
{
	ReleaseDC(hWnd, g_hWinDC);
	ReleaseDC(NULL, g_hDesktopDC);
	g_hWinDC = NULL;
	g_hDesktopDC = NULL;
	KillTimer(hWnd, IDT_TIMER1);
}
