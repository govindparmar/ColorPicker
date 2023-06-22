#include "CP.h"

HDC g_hWinDC = NULL, g_hDesktopDC = NULL;
HWND g_hEdit = NULL, g_hStatic = NULL;

VOID CALLBACK TimerProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ UINT_PTR idEvent, _In_ DWORD dwTime)
{
	POINT p;
	COLORREF pixel;
	WCHAR pxTxt[15];
	WCHAR msTxt[40];
	RECT rc;

	rc.top = 10;
	rc.left = 100;
	rc.bottom = 80;
	rc.right = 180;

	GetCursorPos(&p);
	if (NULL == g_hDesktopDC || NULL == g_hWinDC)
	{
		return;
	}


	pixel = GetPixel(g_hDesktopDC, p.x, p.y);
	if (NULL == g_hEdit)
	{
		g_hEdit = FindWindowExW(hWnd, NULL, L"Edit", NULL);
	}
	if (NULL == g_hStatic)
	{
		g_hStatic = FindWindowExW(hWnd, NULL, L"Static", NULL);
	}

	StringCchPrintfW(pxTxt, 15, L"0x%.8X", pixel);
	StringCchPrintfW(msTxt, 40, L"(%I32d, %I32d)", p.x, p.y);

	SetWindowTextW(g_hEdit, pxTxt);
	SetWindowTextW(g_hStatic, msTxt);

	FillRect(g_hWinDC, &rc, CreateSolidBrush(pixel));

	return;
}
