#pragma once
#include <Windows.h>
#include <windowsx.h>
#include <CommCtrl.h>
#include <strsafe.h>
#include <sal.h>

#define EXTERN extern
#define IDT_TIMER1 1001

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

EXTERN CONST WCHAR g_wszClassName[];
EXTERN HDC g_hWinDC, g_hDesktopDC;
EXTERN HWND g_hEdit, g_hStatic;
EXTERN RECT g_rcSquare;

BOOL CALLBACK EnumChildProc(_In_ HWND hWnd, _In_ LPARAM lParam);
BOOL WINAPI OnCreate(_In_ HWND hWnd, _In_ LPCREATESTRUCTW lpCreateStruct);
VOID WINAPI OnClose(_In_ HWND hWnd);
VOID WINAPI OnDestroy(_In_ HWND hWnd);
VOID WINAPI OnKeydown(_In_ HWND hWnd, _In_ UINT uVK, _In_ BOOL fDown, _In_ INT nRepeat, _In_ UINT uFlags);
VOID WINAPI OnKillFocus(_In_ HWND hWnd, _In_ HWND hWndNewFocus);
VOID WINAPI OnPaint(_In_ HWND hWnd);
VOID WINAPI OnSetFocus(_In_ HWND hWnd, HWND hWndOldFocus);
ATOM WINAPI RegisterWCEX(_In_ HINSTANCE hInstance);
VOID CALLBACK TimerProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ UINT_PTR idEvent, _In_ DWORD dwTime);
LRESULT CALLBACK WindowProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ WPARAM wParam, _In_ LPARAM lParam);
INT APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ INT nShowCmd);
