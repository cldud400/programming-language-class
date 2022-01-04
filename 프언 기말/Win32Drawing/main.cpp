#include <windows.h>
//#include "resource.h"
#include <iostream> // sprintf_s 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nShowCmd)
{
	HWND hWnd;
	MSG mSg;
	char szTitle[] = "정대만";
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
	HPEN hPen;	static POINT pOint;

	switch (uMsg)
	{

	case WM_LBUTTONDOWN: // 마우스 클릭한 상태
		//nX = LOWORD(lParam);
		//nY = HIWORD(lParam);
		//SetPixel(hDCm, nX, nY, RGB(255, 0, 0));
		nAx = LOWORD(lParam);
		nAy = HIWORD(lParam);
		bSw = TRUE;
		return FALSE;
	case WM_RBUTTONDOWN:
		nBx = LOWORD(lParam);
		nBy = HIWORD(lParam);
		bSw = FALSE;
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		return FALSE;

	case WM_PAINT:
		if (bSw == FALSE) {
			hDC = BeginPaint(hWnd, &pS);
			hPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
			SelectObject(hDC, hPen);
			MoveToEx(hDC, nAx, nAy, &pOint); //A에서
			LineTo(hDC, nBx, nBy); //B까지
			DeleteObject(hPen);
			ReleaseDC(hWnd, hDC);
			EndPaint(hWnd, &pS);
		}
		return FALSE;

		
		
		
		//여기에 프로그램을 만들면 된다.
	
	
	
	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}