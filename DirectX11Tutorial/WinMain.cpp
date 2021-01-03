#include <Windows.h>

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
	const auto pClassName = L"hw3dbuttslol";
	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
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
		0, pClassName, L"Happy Hard Window",
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

	//// message pump
	//MSG msg;
	//while (GetMessage(&msg, nullptr, 0, 0) > 0)
	//{
	//	TranslateMessage(&msg);
	//	DispatchMessage(&msg);
	//}

	while (true);
	return 0;
}


LRESULT CALLBACK WndProc(
	HWND   hWnd,
	UINT   message,
	WPARAM wParam,
	LPARAM lParam
)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}