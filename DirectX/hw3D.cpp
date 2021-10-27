#include<Windows.h>

LRESULT CALLBACK wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch (msg)
	{
	case WM_CLOSE:
	PostQuitMessage(0);
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdline, int nCmdShow)
{
	const auto pClassName = "D3D WINDOW";

	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = wndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = LPCWSTR(pClassName);
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	//create window
	HWND hWnd = CreateWindowEx(0,
		LPCWSTR(pClassName),
		LPCWSTR ("NEW WINDOW"),
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 800, 600,
		nullptr, nullptr, hInstance, nullptr);
	//show window
	ShowWindow(hWnd, SW_SHOW);
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}