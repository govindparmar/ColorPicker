#include "CP.h"

VOID WINAPI OnKeydown(_In_ HWND hWnd, _In_ UINT uVK, _In_ BOOL fDown, _In_ INT nRepeat, _In_ UINT uFlags)
{
	if(uVK == VK_F8)
		KillTimer(hWnd, IDT_TIMER1);
	else if(uVK == VK_F9)
		SetTimer(hWnd, IDT_TIMER1, 10, TimerProc);
}