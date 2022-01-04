#include <windows.h>
#include "resource.h"
#include <iostream>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;
HBITMAP hBmpAir, hBmpBack, hBmpBullet, hBmpEnemy, hBmpExplosion;
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
	

	hBmpAir = LoadBitmap(hInstance, "IDB_AIR");
	hBmpBack = LoadBitmap(hInstance, "IDB_BACK");
	hBmpBullet = LoadBitmap(hInstance, "IDB_BULLET");
	hBmpEnemy = LoadBitmap(hInstance, "IDB_ENEMY");
	hBmpExplosion = LoadBitmap(hInstance, "IDB_EXPLOSION");

	InvalidateRect(hWnd, NULL, TRUE);
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
	HDC hDC, hMemDC, hMemDC1;
	static int nX = 0, nY = 0;
	static int nX_back = 0;
	static int nXb, nYb;
	static int nXe, nYe;
	static bool bullet = false;
	static bool enemy = false;
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
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_UP:
			nY -= 20;
			break;
		case VK_DOWN:
			nY += 20;
			break;
		case VK_LEFT:
			nX -= 20;
			nX_back += 3;
			break;
		case VK_RIGHT:
			nX += 20;
			nX_back -= 3;
			break;

		case VK_INSERT:
			SetTimer(hWnd, 1, 10, NULL);
			break;
		case VK_DELETE:
			KillTimer(hWnd, 1);
			break;
		case VK_RETURN:
			nXb = nX + 127;
			nYb = nY;
			SetTimer(hWnd, 2, 2000, NULL);
			enemy = true;
			break;
		case VK_SPACE:
			nXb = nX + 127;
			nYb = nY;
			if (!bullet)
			{
				SetTimer(hWnd, 1, 5, NULL);
				bullet = true;
			}
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);

		return FALSE;

	case WM_TIMER:
		hDC = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);
		if (wParam == 1)
		{
			nXb += 5;
			if (nXb > 640)
			{
				KillTimer(hWnd, 1);
				bullet = false;
			}
		}
		if (wParam == 2)
		{
			nXe = (rand() % 308) + 300;
			nYe = (rand() % 230);
		}
		if (nXb >= nXe - 15 && nXb <= nXe + 15 && nYb >= nYe - 15 && nYb <= nYe + 10)
		{
			bullet = false;
			enemy = false;
			KillTimer(hWnd, 1);
			KillTimer(hWnd, 2);
			SelectObject(hMemDC, hBmpExplosion);
			BitBlt(hDC, nXe, nYe+2, 32, 28, hMemDC, 0, 0, SRCCOPY);

			MessageBox(hWnd, "Enemy Killed", "Congraturaions!", NULL);
		}
		/*if (wParam == 3)
		{
			nX += 20;
			nX_back -= 3;
		}*/

		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC);
		DeleteObject(hMemDC);

		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);

		return FALSE;

	case WM_PAINT:
		hDC = GetDC(hWnd);
		hDC = BeginPaint(hWnd, &pS);
		hMemDC = CreateCompatibleDC(hDC);
		
		if (nX < 0)nX = 640;
		else if (nX > 640)nX = 0;
		if (nY < 0)nY = 480;
		else if (nY > 480)nY = 0;

		if (nX_back < 0) nX_back = 640;
		else if (nX_back > 640) nX_back = 0;

		if (enemy)
		{
			SelectObject(hMemDC, hBmpEnemy);
			BitBlt(hDC, nXe, nYe, 32, 32, hMemDC, 0, 0, SRCCOPY);
		}
		if (bullet)
		{
			SelectObject(hMemDC, hBmpBullet);
			BitBlt(hDC, nXb, nYb, 32, 30, hMemDC, 0, 0, SRCCOPY);
		}
		//Airplane
		SelectObject(hMemDC, hBmpAir);
		BitBlt(hDC, nX, nY, 127, 37, hMemDC, 0, 0, SRCCOPY);
		//Background
		SelectObject(hMemDC, hBmpBack);
		BitBlt(hDC, nX_back, 281, 640, 159, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hDC, nX_back-640, 281, 640, 159, hMemDC, 0, 0, SRCCOPY);

		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC);
		EndPaint(hWnd, &pS);
		//DeleteObject(hBmpJ1);



		return FALSE;

		

	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

