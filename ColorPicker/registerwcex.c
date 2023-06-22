#include "CP.h"

CONST WCHAR g_wszClassName[] = L"ColorPickerWnd";

_Check_return_
_Success_(return)

ATOM WINAPI RegisterWCEX(_In_ HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEXW));

	wcex.cbSize = sizeof(WNDCLASSEXW);
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wcex.hIcon =
	wcex.hIconSm = LoadIconW(NULL, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WindowProc;
	wcex.lpszClassName = g_wszClassName;

	return RegisterClassExW(&wcex);
}
