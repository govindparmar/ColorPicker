#include "CP.h"

HDC g_hWinDC = NULL, g_hDesktopDC = NULL;
HWND g_hEdit = NULL, g_hStatic = NULL;
RECT g_rcSquare = { 0 };

VOID CALLBACK TimerProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ UINT_PTR idEvent, _In_ DWORD dwTime)
{
	POINT p;
	COLORREF pixel;
	WCHAR pxTxt[15];
	WCHAR msTxt[50];
	RECT rc;

	GetCursorPos(&p);
	if (NULL == g_hDesktopDC)
	{
		g_hDesktopDC = GetDC(NULL);
	}
	if (NULL == g_hWinDC)
	{
		g_hWinDC = GetDC(hWnd);
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
	StringCchPrintfW(msTxt, 50, L"(%I32d, %I32d)", p.x, p.y);

	SetWindowTextW(g_hEdit, pxTxt);
	SetWindowTextW(g_hStatic, msTxt);

	
		rc.top = 10;
		rc.left = 100;
		rc.bottom = 80;
		rc.right = 180;
	

	FillRect(g_hWinDC, &rc, CreateSolidBrush(pixel));


	return;
}
