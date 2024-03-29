#include "CP.h"

INT APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ INT nShowCmd)
{
	HWND hWnd;
	MSG Msg;
	NONCLIENTMETRICSW ncm;
	HFONT hfDefault;

	ZeroMemory(&ncm, sizeof(NONCLIENTMETRICSW));
	ncm.cbSize = sizeof(NONCLIENTMETRICSW);
	SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICSW), &ncm, FALSE);
	hfDefault = CreateFontIndirectW(&ncm.lfMessageFont);

	if(RegisterWCEX(hInstance) == (ATOM)0)
	{
		MessageBoxW(NULL, L"Window Registration Failed", L"Error", MB_OK | MB_ICONSTOP);
		return -1;
	}

	hWnd = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, g_wszClassName, L"Color Picker", WS_VISIBLE | WS_SYSMENU, 100, 100, 200, 150, NULL, NULL, hInstance, NULL);
	if(NULL == hWnd)
	{
		MessageBoxW(NULL, L"Window Creation Failed", L"Error", MB_OK | MB_ICONSTOP);
		return -1;
	}

	ShowWindow(hWnd, SW_SHOW);
	EnumChildWindows(hWnd, EnumChildProc, (LPARAM)&hfDefault);
	UpdateWindow(hWnd);

	while(GetMessageW(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessageW(&Msg);
	}

	return (INT) Msg.wParam;
}
