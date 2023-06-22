#include "CP.h"

VOID WINAPI OnClose(_In_ HWND hWnd)
{
	ReleaseDC(NULL, g_hDesktopDC);
	ReleaseDC(hWnd, g_hWinDC);

	DestroyWindow(hWnd);
}
