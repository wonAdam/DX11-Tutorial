#include <Windows.h>
#include <sstream>
#include "WindowsMessageMap.h"

LRESULT CALLBACK WndProc(
	HWND   hWnd,
	UINT   message,
	WPARAM wParam,
	LPARAM lParam
);

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow
)
{
	LPCSTR pClassName = "hw3dbuttslol";
	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	// Main window size
	RECT rc = { 0, 0, 640, 480 };
	// create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName, "Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200,
		//rc.right - rc.left, rc.bottom - rc.top,
		640, 480,
		NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
	{
		return 1;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// message loop
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// GetMessage Error
	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}


LRESULT CALLBACK WndProc(
	HWND   hWnd,
	UINT   message,
	WPARAM wParam,
	LPARAM lParam
)
{
	static WindowsMessageMap mm;
	OutputDebugString( mm(message, lParam, wParam).c_str() );

	switch (message)
	{
		case WM_CLOSE:
			PostQuitMessage(69);
			break;
		case WM_KEYDOWN:
			if (wParam == 'F')
			{
				SetWindowText(hWnd, "Respect");
			}
			break;
		case WM_KEYUP: 
			if (wParam == 'F')
			{
				SetWindowText(hWnd, "Danger");
			}
			break;
		case WM_CHAR: // Translated by TranslateMessageuse, this for character input, letter
			{
				static std::string title;
				title.push_back((char)wParam);
				SetWindowText(hWnd, title.c_str());
			}
			break;
		case WM_LBUTTONDOWN:
			{
			const POINTS pt = MAKEPOINTS(lParam);
			std::ostringstream oss;
			oss << "(" << pt.x << ", " << pt.y << ")";
			SetWindowText(hWnd, oss.str().c_str());
			}
			
			break;
	}

	// behavior
	return DefWindowProc(hWnd, message, wParam, lParam);
}