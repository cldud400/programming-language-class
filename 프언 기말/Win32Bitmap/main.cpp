#include <windows.h>
//#include "resource1.h"
#include <iostream>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK About(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hInst;
HBITMAP hBmp;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nShowCmd)
{
	HWND hWnd;
	MSG mSg;

	hInst = hInstance;

	char szTitle[] = "불꽃남자정대만";
	char szClass[] = "Class";
	WNDCLASSEX WndEx;
	WndEx.cbSize = sizeof(WndEx);
	WndEx.style = NULL;
	WndEx.lpfnWndProc = WndProc;
	WndEx.cbClsExtra = 0;
	WndEx.cbWndExtra = 0;
	WndEx.hInstance = hInstance;
	WndEx.hIcon = LoadIcon(NULL, "");
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndEx.lpszMenuName = "";
	WndEx.lpszClassName = szClass;
	WndEx.hIconSm = LoadIcon(hInstance, "");
	RegisterClassEx(&WndEx);
	hWnd = CreateWindowEx(NULL, szClass, szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		320 * 2, 240 * 2, NULL, NULL, hInstance, NULL); // 윈도우창 사이즈
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);
	hBmp = LoadBitmap(hInstance, "IDB_BITMAP");
	while (TRUE)
	{
		if (PeekMessage(&mSg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&mSg, NULL, 0, 0))
				break;
			TranslateMessage(&mSg);
			DispatchMessage(&mSg);
		}
	}
	return mSg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,
	UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC, hMemDC;;
	HDC hDCm = GetDC(hWnd);
	char szTitle[] = "둥근해가 떴습니다.";
	char szText[] = "자리에서 일어나서";
	char szText1[] = "Mouse left button down.";
	char szText2[] = "Mouse left button up.";
	char szText3[] = "Mouse right button down.";
	char szText4[] = "Mouse right button up.";
	char szTextc[100];
	char szTextf[] = "Don't follow me~~~";

	static int a = 1, m = 0, s = 0, m2 = 0, s2 = 0;

	static int x = 100, y = 100;
	static int keyflag = 0;
	static BOOL bSw = TRUE;
	static int nAx, nAy, nBx, nBy;


	static POINT pOint;

	static HWND hButtPrint, hButtExit, hEdit, hButtDialog;


	switch (uMsg)
	{
		//main structure
	case WM_CREATE:
		hButtPrint = CreateWindow("BUTTON", "Load Bitmap", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 250, 90, 30, hWnd, (HMENU)1,//button ID
			NULL, NULL);
		hButtExit = CreateWindow("BUTTON", "Exit", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 250, 90, 30, hWnd, (HMENU)2,//button ID
			NULL, NULL);
		return FALSE;

	case WM_COMMAND:
		if (LOWORD(wParam) == 1) {
			hDC = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hDC);
			SelectObject(hMemDC, hBmp);
			BitBlt(hDC, 0, 0, 389, 387, hMemDC, 0, 0, SRCCOPY);
			DeleteDC(hMemDC);
			ReleaseDC(hWnd, hDC);
			DeleteObject(hBmp);
		}
		if (LOWORD(wParam) == 2) {
			PostQuitMessage(0);
		}
		return FALSE;



	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


LRESULT CALLBACK About(HWND hDlg,
	UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return FALSE;
}