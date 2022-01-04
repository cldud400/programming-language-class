#include <windows.h>
#include "resource.h"
#include <iostream> // sprintf_s 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK About(HWND hDlg,
	UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hInst;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nShowCmd)
{
	HWND hWnd;
	MSG mSg;
	char szTitle[] = "정대만";
	char szClass[] = "Class";
	hInst = hInstance;
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
	HDC hDCm = GetDC(hWnd);
	char szTitle[] = "혜지는 변혜지";
	char szText[] = "예빈이는 설예빈";
	char szText1[] = "Mouse left button down.";
	char szText2[] = "Mouse left button up.";
	char szText3[] = "Mouse right button down.";
	char szText4[] = "Mouse right button up.";
	char szTextf[] = "가영이는 민가영";
	static int a = 1, m = 0, s = 0, s2 = 0, m2 = 0;
	static int x = 100, y = 100;
	static int keyflag = 0;
	int nX, nY;
	char szTextc[100];
	PAINTSTRUCT pS;
	static int nAx, nAy, nBx, nBy;
	static BOOL bSw = TRUE;
	HPEN hPen;
	static POINT pOint;
	static HWND hButtPrint, hButtExit;
	static HWND hEdit, hButtDialog;

	switch (uMsg)
	{
	case WM_CREATE:
		hButtPrint = CreateWindow("BUTTON", "Output", WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON,
			60, 60, 90, 30, hWnd, (HMENU)1, //위치,위치,크기,크기
			NULL, NULL);
		hButtExit = CreateWindow("BUTTON", "Exit", WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON,
			160, 60, 90, 30, hWnd, (HMENU)2,// button ID (Param이랑 동일)
			NULL, NULL);
		hButtDialog = CreateWindow("BUTTON", "Dialog", WS_CHILD | WS_VISIBLE |
			BS_PUSHBUTTON,
			60, 260, 90, 30, hWnd, (HMENU)4, 
			NULL, NULL);
		hEdit = CreateWindow("EDIT", "Edit", WS_CHILD | WS_VISIBLE |
			WS_BORDER,
			160, 140, 90, 30, hWnd, (HMENU)3,
			NULL, NULL);
		return FALSE;

	case WM_COMMAND:
		/*switch (LOWORD(wParam))
		{
		case 1:
			MessageBox(hWnd, "오늘은 목요일", "Output", NULL);
		case 2:
			PostQuitMessage(0);
		} if랑 같다*/
		if (LOWORD(wParam) == 1) {
			MessageBox(hWnd, "오늘은 목요일", "Output", NULL);
		}
		if (LOWORD(wParam) == 2) {
			PostQuitMessage(0);
		} 
		if (LOWORD(wParam) == 4) {
			DialogBox(hInst,"IDD_DIALOG", hWnd,DLGPROC(About));
		}
		return FALSE;
	




		//여기에 프로그램을 만들면 된다.



	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
LRESULT CALLBACK About(HWND hDlg,
	UINT uMsg, WPARAM wParam, LPARAM lParam);
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTT_EXIT) 
		EndDialog(hDlg, 0);
		break;
	}
	return FALSE;
}