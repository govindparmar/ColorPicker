#include "CP.h"

BOOL WINAPI OnCreate(_In_ HWND hWnd, _In_ LPCREATESTRUCTW lpCreateStruct)
{
	INITCOMMONCONTROLSEX iccx;
	HWND hEdit, hStatic, hStatic2;
	HINSTANCE hInstance = lpCreateStruct->hInstance;

	iccx.dwICC = ICC_STANDARD_CLASSES;
	iccx.dwSize = sizeof(INITCOMMONCONTROLSEX);

	InitCommonControlsEx(&iccx);

	hEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_READONLY, 10, 10, 80, 20, hWnd, NULL, hInstance, NULL);
	hStatic = CreateWindowExW(0, L"Static", L"", WS_VISIBLE | WS_CHILD, 10, 30, 80, 20, hWnd, NULL, hInstance, NULL);
	hStatic2 = CreateWindowExW(0, L"Static", L"Press F8 to pause/F9 to resume", WS_VISIBLE | WS_CHILD, 10, 90, 180, 20, hWnd, NULL, hInstance, NULL);

	SetTimer(hWnd, IDT_TIMER1, 10, TimerProc);

	return TRUE;
}