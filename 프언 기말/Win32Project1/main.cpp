#include <windows.h>
#include "resource.h"
#include <iostream> // sprintf_s 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nShowCmd)
{
	HWND hWnd;
	MSG mSg;
	char szTitle[] = "���븸";
		char szClass[] = "Class";
	WNDCLASSEX WndEx;
	WndEx.cbSize = sizeof(WndEx);
	WndEx.style = NULL;
	WndEx.lpfnWndProc = WndProc;
	WndEx.cbClsExtra = 0;
	WndEx.cbWndExtra = 0;
	WndEx.hInstance = hInstance;
	WndEx.hIcon = LoadIcon(NULL, "IDI_ICON2");
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndEx.lpszMenuName = "IDR_MENU";
	WndEx.lpszClassName = szClass;
	WndEx.hIconSm = LoadIcon(hInstance, "IDI_ICON2");
	RegisterClassEx(&WndEx);
	hWnd = CreateWindowEx(NULL, szClass, szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		320 * 2, 240 * 2, NULL, NULL, hInstance, NULL); // ������â ������
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
	UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	HDC hDC;
	HDC hDCm = GetDC(hWnd);
	char szTitle[] = "������ ������";
	char szText[] = "�����̴� ������";
	char szText1[] = "Mouse left button down.";
	char szText2[] = "Mouse left button up.";
	char szText3[] = "Mouse right button down.";
	char szText4[] = "Mouse right button up.";
	char szTextf[] = "�����̴� �ΰ���";
	static int a = 1, m = 0, s = 0, s2 = 0, m2 = 0;
	static int x = 100, y = 100;
	static int keyflag = 0;
	int nX, nY;
	char szTextc[1000];



	PAINTSTRUCT pS;

	switch (uMsg)
	{
	case WM_MOUSEMOVE:
		hDC = GetDC(hWnd);
		nX = LOWORD(lParam);
		nY = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, TRUE); //��� ���� �ʱ�ȭ
		UpdateWindow(hWnd);
		sprintf_s(szTextc, "nX:%d, nY:%d", nX, nY);
		TextOut(hDCm, 5, 25, szTextc, lstrlen(szTextc));
		TextOut(hDCm, nX, nY, szTextf, lstrlen(szTextf));
		return FALSE;
	case WM_LBUTTONDOWN: // ���콺 Ŭ���� ����
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		TextOut(hDCm, 5, 200, szText1, lstrlen(szText1)); return FALSE;
	case WM_LBUTTONUP: // ������ Ŭ�� ���� ����
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		TextOut(hDCm, 5, 200, szText2, lstrlen(szText2)); return FALSE;
	case WM_RBUTTONDOWN:
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		TextOut(hDCm, 5, 200, szText3, lstrlen(szText3)); return FALSE;
	case WM_RBUTTONUP:
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		TextOut(hDCm, 5, 200, szText4, lstrlen(szText4)); return FALSE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case FILE_EXIT:
			PostQuitMessage(0);
			break;
		case HELP_ABOUT:
			MessageBox(hWnd, "Window Menu Test", "Output", NULL);
			break;
		}
		return FALSE;
	case WM_PAINT: // ȭ������� ������ ������
		hDC = BeginPaint(hWnd, &pS);
		TextOut(hDC, 5, 65, szText, lstrlen(szText)); // �������ٰ� �ٽû���
		sprintf_s(szTextc, "X-coordinate,:%d, Y-coordinate:%d", x, y);
		TextOut(hDC, 5, 5, szTextc, lstrlen(szTextc));
		EndPaint(hWnd, &pS);
		return FALSE;
	case WM_TIMER:
		if (wParam == 1) {
			s++;
			if (s == 60) { s = 0; m++; }
			if (m == 60) { m = 0; }
			sprintf_s(szTextc, "Minute:%dmin Second:%dsec", m, s);
			TextOut(hDCm, 5, 200, szTextc, lstrlen(szTextc));
		}
		if (wParam == 2) {
			s2++;
			if (s2 == 60) { s2 = 0; m2++; }
			if (m2 == 60) { m2 = 0; }
			sprintf_s(szTextc, "Minute:%dmin Second:%dsec", m2, s2);
			TextOut(hDCm, 205, 200, szTextc, lstrlen(szTextc));
		}
		return FALSE;

	case WM_KEYDOWN: // Ű���带 ������ ���
		if (LOWORD(wParam) == VK_F1)
		{
			SetTimer(hWnd, 1, 10, NULL);			SetTimer(hWnd, 2, 100, NULL);
		}
		if (LOWORD(wParam) == VK_END)
		{
			KillTimer(hWnd, 1);
			KillTimer(hWnd, 2);
		}
		if (LOWORD(wParam) == VK_RETURN) //Enter�� ������ ���
		{
			hDC = GetDC(hWnd);
			SetTextColor(hDC, RGB(255, 0, 0));
			TextOut(hDC, 5, 5, szText, lstrlen(szText));
			SetTextColor(hDC, RGB(0, 255, 0));
			TextOut(hDC, 5, 25, szText2, lstrlen(szText2));
			SetTextColor(hDC, RGB(0, 0, 255));
			TextOut(hDC, 5, 45, szText3, lstrlen(szText3));
		}
		if (LOWORD(wParam) == VK_DELETE) // Delete�� ������ ���
		{
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
		}
		if (LOWORD(wParam) == VK_SPACE) //Space�� ������ ���
		{
			SetWindowText(hWnd, szTitle); // Title�� �ٲ��
		}
		if (LOWORD(wParam) == VK_HOME)
		{
			switch (a) {
			case 1: // ȭ���� ��İ�
				SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(DKGRAY_BRUSH));
				InvalidateRect(hWnd, NULL, TRUE);
				a = 2;
				break;
			case 2: // ȭ���� �Ͼ��
				SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(WHITE_BRUSH));
				InvalidateRect(hWnd, NULL, TRUE);
				a = 1;
				break;
			}

		}
		keyflag = 0;
		switch (LOWORD(wParam)) {
		case VK_UP:
			y = y - 5; keyflag = 1; break;
		case VK_DOWN:
			y = y + 5; keyflag = 1; break;
		case VK_LEFT:
			x = x - 5; keyflag = 1; break;
		case VK_RIGHT:
			x = x + 5; keyflag = 1; break;
		}
		if (keyflag == 1) {
			MoveWindow(hWnd, x, y, 320 * 2, 240 * 2, TRUE);
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
		}
		return FALSE;
	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}