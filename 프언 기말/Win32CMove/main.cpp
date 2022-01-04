#include <windows.h>
//#include "resource1.h"
#include <iostream>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
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
	hBmp = LoadBitmap(hInstance, "");
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
	HDC hDC;
	static int nX1 = 0, nY1 = 40, nX2 = 20, nY2 = 60;
	static int nSw = 1;
	PAINTSTRUCT pS;
	HPEN hPen;
	static HWND hButtHori, hButtVert, hButtDiago;

	switch (uMsg)
	{
		//main structure
	case WM_KEYDOWN: // 키보드를 누르는 경우
		if (LOWORD(wParam) == VK_RETURN)
		{
			SetTimer(hWnd, 1, 10, NULL);
				}
		if (LOWORD(wParam) == VK_SPACE)
		{
			KillTimer(hWnd, 1);	
		}
		return FALSE;
	case WM_CREATE:
		hButtHori = CreateWindow("BUTTON", "Hori", WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON,
			60, 60, 90, 30, hWnd, (HMENU)1, //위치,위치,크기,크기
			NULL, NULL);
		hButtVert = CreateWindow("BUTTON", "Vert", WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON,
			160, 60, 90, 30, hWnd, (HMENU)2,// button ID (Param이랑 동일)
			NULL, NULL);
		hButtDiago = CreateWindow("BUTTON", "Diago", WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON,
			260, 60, 90, 30, hWnd, (HMENU)3,
			NULL, NULL);
		return FALSE;

	case WM_TIMER:
		hDC = GetDC(hWnd);
		InvalidateRect(hWnd, NULL, TRUE); //모든 값을 초기화
		UpdateWindow(hWnd);
		switch (nSw)
		{
		case 1:
			nX1 = nX1 + 5;
			nX2 = nX2 + 5;
			if (nX2 >= 620)
				nSw = 2;
			return FALSE;
			break;
		
		case 2:
			nX1 = nX1 - 5;
			nX2 = nX2 - 5;
			if (nX2 <= 20)
				nSw = 1;
			return FALSE;
			break;

		case 3:
			nY1 = nY1 + 5;
			nY2 = nY2 + 5;
			if (nY2 >= 450)
				nSw = 4;
			return FALSE;
			break;
		
		case 4:
			nY1 = nY1 - 5;
			nY2 = nY2 - 5;
			if (nY2 <= 20)
				nSw = 3;
			return FALSE;
			break;
		
		case 5:
			nX1 = nX1 + 5;
			nX2 = nX2 + 5;
			nY1 = nY1 + 5;
			nY2 = nY2 + 5;
			if (nY2 >= 450 || nX2 >= 620)
				nSw = 6;
			return FALSE;
			break;
		
		case 6:
			nX1 = nX1 - 5;
			nX2 = nX2 - 5;
			nY1 = nY1 - 5;
			nY2 = nY2 - 5;
			if (nY2 <= 20 || nY2 <= 20)
				nSw = 5;
			return FALSE;
			break;
		
			}
		return FALSE;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pS);
		hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		SelectObject(hDC, hPen);
		Ellipse(hDC, nX1, nY1, nX2, nY2);
		EndPaint(hWnd, &pS);
		return FALSE;

	
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 1:
			nSw = 1; 
			return FALSE;
			break;
		case 2:
			nSw = 3; 
			return FALSE;
			break;
		case 3:
			nSw = 5;
			return FALSE;
			break;

		}



	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//1번버튼 디랙션 1 -> time문으로 가서 디랙션 1일떄 가로