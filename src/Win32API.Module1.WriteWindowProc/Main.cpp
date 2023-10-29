#include <Windows.h>
#include <tchar.h>
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SIZE:
		{
			int width = LOWORD(lParam); // Macro to get the low-order word.
			int height = HIWORD(lParam); // Macro to get the high-order word.


			// Respond to the message:
			OnSize(hWnd, (UINT)wParam, width, height);
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void OnSize(HWND hwnd, UINT flag, int width, int height)
{
	// Handle resizing
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = _T("Sample Window Class");

	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Learn to Program Windows",
		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (hwnd == NULL)
	{
		return 1;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}