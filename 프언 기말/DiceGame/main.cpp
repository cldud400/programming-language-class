#include <windows.h>
//#include "resource1.h"
#include <iostream>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;
HBITMAP hBmpJ1, hBmpJ2, hBmpJ3, hBmpJ4, hBmpJ5, hBmpJ6 ;
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
	HDC hDC, hMemDC, hMemDC1;
	static int nX1 = 0, nY1 = 40, nX2 = 20, nY2 = 60;
	static int nSw = 1;
	PAINTSTRUCT pS;
	HPEN hPen;
	
	static HWND hButtStart, hButtStop, hButtExit;
	static int a, ma, b, mb;
	char szText1[] = "자리에서 일어나서";
	char szText2[] = "자리에서 일어나서";
	char szText3[] = "자리에서 일어나서";

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
		switch (LOWORD(wParam))
		{
		case 1:
			SetTimer(hWnd, 1, 1, NULL);
			return FALSE;
		case 2:
			hDC = GetDC(hWnd);
			sprintf_s(szText1, "Score: %d", a);
			sprintf_s(szText2, "Score: %d", b);
			sprintf_s(szText3, "Score total: %d", a+b);
			TextOut(hDC, 400, 400, szText1, lstrlen(szText1));
			TextOut(hDC, 460, 400, szText2, lstrlen(szText2));
			TextOut(hDC, 520, 400, szText3, lstrlen(szText3));
			KillTimer(hWnd, 1);
			return FALSE;
		case 3:
			PostQuitMessage(0);
			return FALSE;

		}
	case WM_TIMER:
		hDC = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);
		hMemDC1 = CreateCompatibleDC(hDC);
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		a = rand(); ma = a % 6; a = ma + 1;
		b = rand(); mb = b % 6; b = mb + 1;


		switch(a)
		{
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
		switch (b)
		{
		case 1:
			SelectObject(hMemDC1, hBmpJ1);
			break;
		case 2:
			SelectObject(hMemDC1, hBmpJ2);
			break;
		case 3:
			SelectObject(hMemDC1, hBmpJ3);
			break;
		case 4:
			SelectObject(hMemDC1, hBmpJ4);
			break;
		case 5:
			SelectObject(hMemDC1, hBmpJ5);
			break;
		case 6:
			SelectObject(hMemDC1, hBmpJ6);
			break;
		default:
			break;
		}

		

		BitBlt(hDC, ma*100, mb*60, 88, 88, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hDC, ma * 40, mb * 20, 88, 88, hMemDC1, 0, 0, SRCCOPY);
		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC);
		//DeleteObject(hBmpJ1);



		return FALSE;



	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//1번버튼 디랙션 1 -> time문으로 가서 디랙션 1일떄 가로