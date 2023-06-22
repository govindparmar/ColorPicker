#include "CP.h"

VOID WINAPI OnClose(_In_ HWND hWnd)
{
	ReleaseDC(NULL, g_hDesktopDC);
	ReleaseDC(hWnd, g_hWinDC);
	g_hDesktopDC = NULL;
	g_hWinDC = NULL;

	DestroyWindow(hWnd);
}
