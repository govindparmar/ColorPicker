#include "CP.h"

VOID WINAPI OnKeyDown(
	_In_ HWND hWnd, 
	_In_ UINT uVK, 
	_In_ BOOL fDown, 
	_In_ INT nRepeat, 
	_In_ UINT uFlags
)
{
	if (VK_F8 == uVK)
	{
		KillTimer(hWnd, IDT_TIMER1);
	}
	else if (VK_F9 == uVK)
	{
		SetTimer(hWnd, IDT_TIMER1, 10, TimerProc);
	}
}
