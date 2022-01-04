#include <windows.h>
//#include "resource1.h"
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
	HDC hDC, hMemDC;
	static int nX = 0, nY = 0; //airplane
	static int nX_back = 0;
	static int nXb[10], nYb[10]; //bullet[개수]
	static bool bullet[10] = { 0,0,0,0,0,0,0,0,0,0 };
	static bool hit[10] = { 0,0,0,0,0,0,0,0,0,0 };
	static int nXe, nYe; //enemy
	static bool enemy = false;
	static int max_no_of_bullet = 9;
	static int no_of_fire = 0, no_of_hit = 0;
	static int bn = 0;
	char szText[100];
	int i;
	PAINTSTRUCT pS;


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
			SetTimer(hWnd, max_no_of_bullet+2, 2000, NULL);
			enemy = true;
			break;
		case VK_SPACE: //start
			no_of_fire++;
			nXb[bn] = nX + 127;
			nYb[bn] = nY;
			if (!bullet[bn])
			{
				SetTimer(hWnd, bn+1, 5, NULL);
				bullet[bn] = true;
			}
			bn++;
			if (bn > max_no_of_bullet)bn = 0;
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);

		return FALSE;

	case WM_TIMER:
		hDC = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);

		for (i = 0; i <= max_no_of_bullet; i++)
		{
			if (wParam == i+1) //timer no.1
			{
				nXb[i] += 5;
				if (nXb[i] > 640)
				{
					KillTimer(hWnd, i+1);
					bullet[i] = false;
				}
			}
		}
		if (wParam == max_no_of_bullet+2) //timer no.2
		{
			nXe = (rand() % 308) + 300;
			nYe = (rand() % 230);
		}
		for (i = 0; i <= max_no_of_bullet; i++) 
		{
			if (nXb[i] >= nXe - 15 && nXb[i] <= nXe + 15 && nYb[i] >= nYe - 15 && nYb[i] <= nYe + 15)
			{
				bullet[i] = false;
				//enemy = false;
				KillTimer(hWnd, i + 1);
				//KillTimer(hWnd, 2); //game over
				hit[i] = TRUE;
				no_of_hit++;

				//MessageBox(hWnd, "Enemy Killed", "Congraturaions!", NULL);
			}
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
		for (i = 0; i <= max_no_of_bullet; i++) 
		{
			if (bullet[i])
			{
				SelectObject(hMemDC, hBmpBullet);
				BitBlt(hDC, nXb[i], nYb[i], 32, 30, hMemDC, 0, 0, SRCCOPY);
			}
			if (hit[i])
			{
				SelectObject(hMemDC, hBmpExplosion);
				BitBlt(hDC, nXe, nYe + 2, 32, 28, hMemDC, 0, 0, SRCCOPY);
				hit[i] = 0;
			}
		}
		//Airplane
		SelectObject(hMemDC, hBmpAir);
		BitBlt(hDC, nX, nY, 127, 37, hMemDC, 0, 0, SRCCOPY);
		//Background
		SelectObject(hMemDC, hBmpBack);
		BitBlt(hDC, nX_back, 281, 640, 159, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hDC, nX_back - 640, 281, 640, 159, hMemDC, 0, 0, SRCCOPY);

		sprintf_s(szText, " No of fired : %d, No of hit : %d", no_of_fire, no_of_hit);
		TextOut(hDC, 300, 10, szText, lstrlen(szText));

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

//메뉴 만들어 오기