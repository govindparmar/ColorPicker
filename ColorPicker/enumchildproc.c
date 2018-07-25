#include "CP.h"

BOOL CALLBACK EnumChildProc(_In_ HWND hWnd, _In_ LPARAM lParam)
{
	HFONT hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	SendMessageW(hWnd, WM_SETFONT, (WPARAM)hfDefault, 0);
	return TRUE;
}