#include <windows.h>
#include "resource.h"
#include <iostream>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;
HBITMAP hBmpAir, hBmpBack;
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
	WndEx.lpszMenuName = "IDR_MENU";
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
	hBmpAir = LoadBitmap(hInstance, "IDB_AIR");
	hBmpBack = LoadBitmap(hInstance, "IDB_BACK");

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
	HDC hDC, hMemDC, hDC1;
	static int nX1 = 0, nY1 = 40, nX2 = 20, nY2 = 60;
	static int nSw = 1;
	PAINTSTRUCT pS;
	HPEN hPen;

	static HWND hButtStart, hButtStop, hButtExit;
	static int a, ma, b, mb;
	char szText1[] = "자리에서 일어나서";
	char szText2[] = "자리에서 일어나서";
	char szText3[] = "자리에서 일어나서";
	static int aX = 0, aY = 0;
	static int bX = 0, bY = 264;
	switch (uMsg)
	{
		/*
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
		*/
	case WM_TIMER:
		hDC = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		aX += 2;
		bX -= 2;
		if (bX < 0)bX = 640;
		if (aX > 640)aX = 0;
		SelectObject(hMemDC, hBmpAir); //airplane
		BitBlt(hDC, aX, aY, 127, 37, hMemDC, 0, 0, SRCCOPY);
		SelectObject(hMemDC, hBmpBack); //background
		BitBlt(hDC, bX, bY, 640, 159, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hDC, bX - 640, bY, 640, 159, hMemDC, 0, 0, SRCCOPY);
		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC);
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case  40001:
			SetTimer(hWnd, 1, 1, NULL);
			break;
		case 40002:
			
			KillTimer(hWnd, 1);
			break;
		}
		return FALSE;
	case WM_KEYDOWN:
		switch (LOWORD(wParam)) {
		case VK_UP:
			aY -= 100;
			if (aY <=0) {
				aY = 480;
			}
			break;
		case VK_DOWN:
			aY += 100;
			if (aY >= 480) {
				aY = 0;
			}
			break;
		case VK_LEFT:
			aX -= 100;
			if (aX <= 0) {
				aX = 640;
			}
				bX += 2;
			if (bX >= 640) bX = 0;
			break;
		case VK_RIGHT:
			aX += 100;
			if (aX >= 640) {
				aX = 0;
			}
				bX -= 2;
			if (bX <=0) bX = 640;
			break;
		case VK_SPACE:
			aX = 0, aY = 0;
			bX = 0, bY = 264;
			break;
		}
		
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		return FALSE;
	/*case WM_PAINT:
		hDC1 = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC1);
		

		SelectObject(hMemDC, hBmpAir); //airplane
		BitBlt(hDC1, aX, aY, 127, 37, hMemDC, 0, 0, SRCCOPY);
		SelectObject(hMemDC, hBmpBack); //background
		BitBlt(hDC1, bX, bY, 640, 159, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hDC1, bX-640, bY, 640, 159, hMemDC, 0, 0, SRCCOPY);
		
		
		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC1);
		//DeleteObject(hBmpJ1);*/




		return FALSE;  
		


	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//1번버튼 디랙션 1 -> time문으로 가서 디랙션 1일떄 가로