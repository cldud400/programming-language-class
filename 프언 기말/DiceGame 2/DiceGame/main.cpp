#include <windows.h>
//#include "resource.h"
#include <iostream>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HBITMAP hBmpJ1, hBmpJ2, hBmpJ3, hBmpJ4, hBmpJ5, hBmpJ6;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nShowCmd)
{
	HWND hWnd;
	MSG mSg;
	char szTitle[] = "My First Dice Game";
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

	hBmpJ1 = LoadBitmap(hInstance, "IDB_J1");
	hBmpJ2 = LoadBitmap(hInstance, "IDB_J2");
	hBmpJ3 = LoadBitmap(hInstance, "IDB_J3");
	hBmpJ4 = LoadBitmap(hInstance, "IDB_J4");
	hBmpJ5 = LoadBitmap(hInstance, "IDB_J5");
	hBmpJ6 = LoadBitmap(hInstance, "IDB_J6");

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
	HDC hDC,hDC2,hMemDC,hMemDC2;
	
	char szText[100];//score storage
	char szText2[100];
	char szText3[100];
	

	
	PAINTSTRUCT pS;
	static int x = 100, y = 100;
	static int keyflag = 0;
	static BOOL bSw = TRUE;
	static int nAx, nAy, nBx, nBy;
	HPEN hPen;
	PAINTSTRUCT ps;
	static POINT pOint;

	static HWND hButtStart, hButtStop, hButtExit;
	static int a, ma, b, mb,c,mc,d,md;

	switch (uMsg)
	{
		//main structure

	case WM_CREATE:

		hButtStart = CreateWindow("BUTTON", "Start", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			60, 400, 90, 30, hWnd, (HMENU)1,//button ID
			NULL, NULL);
		hButtStop = CreateWindow("BUTTON", "Stop", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			160, 400, 90, 30, hWnd, (HMENU)2,//button ID
			NULL, NULL);
		hButtExit = CreateWindow("BUTTON", "Exit", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			260, 400, 90, 30, hWnd, (HMENU)3,//button ID
			NULL, NULL);

		return FALSE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case 1:
			SetTimer(hWnd, 1, 100, NULL);
			return FALSE;
		case 2:
			KillTimer(hWnd, 1);
			hDC = GetDC(hWnd);
			//hDC2 = GetDC(hWnd);
			sprintf_s(szText, "Score1 : %d", a);
			TextOut(hDC, 300, 300, szText, lstrlen(szText));
			sprintf_s(szText2, "Score2 : %d", c);
			TextOut(hDC, 400, 300, szText2, lstrlen(szText));
			sprintf_s(szText3, "Total :  %d", a+c);
			TextOut(hDC, 520, 300, szText3, lstrlen(szText));
			return FALSE;
		case 3:
			PostQuitMessage(0);
			return FALSE;
		}
		return FALSE;

	case WM_TIMER:
		hDC = GetDC(hWnd);
		hDC2 = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);
		hMemDC2 = CreateCompatibleDC(hDC2);
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);


		a = rand();
		ma = (a % 6);//0~ma~5
		a = ma + 1;//1~a~6
		b = rand();mb = (b % 6);b = mb + 1;

		c = rand(); mc = (c % 6); c = mc + 1;
		d = rand(); md = (b % 6); d = md + 1;

		switch (a) {
		case 1:
			SelectObject(hMemDC, hBmpJ1);
			break;
		case 2:
			SelectObject(hMemDC, hBmpJ2);
			break;
		case 3:
			SelectObject(hMemDC, hBmpJ3);
			break;
		case 4:
			SelectObject(hMemDC, hBmpJ4);
			break;
		case 5:
			SelectObject(hMemDC, hBmpJ5);
			break;
		case 6:
			SelectObject(hMemDC, hBmpJ6);
			break;
		default:

			break;
		}

		switch (c) {
		case 1:
			SelectObject(hMemDC2, hBmpJ1);
			break;
		case 2:
			SelectObject(hMemDC2, hBmpJ2);
			break;
		case 3:
			SelectObject(hMemDC2, hBmpJ3);
			break;
		case 4:
			SelectObject(hMemDC2, hBmpJ4);
			break;
		case 5:
			SelectObject(hMemDC2, hBmpJ5);
			break;
		case 6:
			SelectObject(hMemDC2, hBmpJ6);
			break;
		default:

			break;
		}


		BitBlt(hDC, ma*90, mb*50, 88, 88, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hDC, mc * 90, md * 50, 88, 88, hMemDC2, 0, 0, SRCCOPY);
		ReleaseDC(hWnd, hDC);
		ReleaseDC(hWnd, hDC2);
		DeleteDC(hMemDC);
		DeleteDC(hMemDC2);
		//DeleteObject(hBmp);

		return FALSE;



	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

