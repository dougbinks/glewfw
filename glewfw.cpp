#include <GL/glewfw.h>




#ifdef _WIN32

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>

GLFWAPI void GLFWAPIENTRY  glewfwToggleFullscreen()
{
	static bool bIsFullScreen = false;
	bIsFullScreen = !bIsFullScreen;
	if( bIsFullScreen )
	{
		HWND hwnd = GetForegroundWindow();
		WINDOWINFO winInfo;
		winInfo.cbSize = sizeof( winInfo );
		GetWindowInfo( hwnd, &winInfo );
		HMONITOR hmon = MonitorFromWindow(hwnd,
										MONITOR_DEFAULTTONEAREST);
		MONITORINFO mi = { sizeof(mi) };
		if (!GetMonitorInfo(hmon, &mi)) return;
		RECT newPos = mi.rcMonitor;
		AdjustWindowRectEx( &newPos, WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE, FALSE, WS_EX_APPWINDOW );

		SetWindowLong( hwnd, GWL_STYLE, WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE );
		SetWindowLong( hwnd, GWL_EXSTYLE, WS_EX_APPWINDOW );
			
		SetWindowPos(
			hwnd, HWND_TOPMOST,
			newPos.left,
			newPos.top,
			newPos.right - newPos.left,
			newPos.bottom - newPos.top, SWP_FRAMECHANGED );
	}
	else
	{
		HWND hwnd = GetForegroundWindow();
		HMONITOR hmon = MonitorFromWindow(hwnd,
										MONITOR_DEFAULTTONEAREST);
		MONITORINFO mi = { sizeof(mi) };
		if (!GetMonitorInfo(hmon, &mi)) return;
		RECT newPos = mi.rcWork;

		SetWindowLong( hwnd, GWL_STYLE, WS_MAXIMIZEBOX | WS_SIZEBOX | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE );
		SetWindowLong( hwnd, GWL_EXSTYLE, WS_EX_WINDOWEDGE | WS_EX_APPWINDOW );
			
		SetWindowPos(
			hwnd, HWND_NOTOPMOST,
			newPos.left,
			newPos.top,
			newPos.right - newPos.left,
			newPos.bottom - newPos.top, SWP_FRAMECHANGED );
	}

}

#endif
#ifdef __APPLE_CC__
GLFWAPI void GLFWAPIENTRY  glewfwToggleFullscreen()
{
}
#endif