#include "CP.h"

VOID CALLBACK TimerProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ UINT_PTR idEvent, _In_ DWORD dwTime)
{
	POINT p;
	HDC winDC, desktopDC;
	COLORREF pixel;
	HWND hEdit, hStatic;
	WCHAR pxTxt[15];
	WCHAR msTxt[15];
	RECT windowRect;

	GetCursorPos(&p);
	desktopDC = GetDC(NULL);
	winDC = GetDC(hWnd);
	pixel = GetPixel(desktopDC, p.x, p.y);
	hEdit = FindWindowExW(hWnd, NULL, L"Edit", NULL);
	hStatic = FindWindowExW(hWnd, NULL, L"Static", NULL);

	StringCchPrintfW(pxTxt, 15, L"0x%.8X", pixel);
	StringCchPrintfW(msTxt, 15, L"(%d, %d)", p.x, p.y);

	SetWindowTextW(hEdit, pxTxt);
	SetWindowTextW(hStatic, msTxt);

	windowRect.top = 10;
	windowRect.left = 100;
	windowRect.bottom = 80;
	windowRect.right = 180;

	FillRect(winDC, &windowRect, CreateSolidBrush(pixel));

	ReleaseDC(NULL, desktopDC);
	ReleaseDC(NULL, winDC);

	DeleteDC(desktopDC);
	DeleteDC(winDC);

	return;
}
