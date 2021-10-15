#include <windows.h>
#include <winuser.h>
#pragma endregion

#define button1 1001
#define button2 1002
#define edit1 1000

static HWND hEditA;

LRESULT WINAPI mainProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp);
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	MSG msg;
	HWND hMain = CreateWindowEx(0,
		WC_DIALOG,
		TEXT("Лабораторная 36"),
		WS_VISIBLE | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		300, 300, 0, 0, 0, 0);

	// CreateWindowEx(0, TEXT("button"), TEXT("Далее"), WS_VISIBLE | WS_CHILD, 50, 73, 80, 20, hMain, (HMENU)1000, 0, 0);

    SetWindowLong(hMain, (int)4, (long*)mainProc);
	// Эта строка посылает сообщение нашему окну,
	// оно обрабатывается функцией mainProc как и другие сообщения.
	SendMessageA(hMain, WM_CREATE, 0, 0);
	while (GetMessage(&msg, 0, 0, 0) != NULL)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT WINAPI mainProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp)
{
	char *bufi = (char*)"******";
	char* bufg = (char*)"      ";
	static int size = 0;

	/*typedef struct _RECT {
		LONG left;
		LONG top;
		LONG right;
		LONG bottom;
	} RECT, * PRECT;

	RECT { 10, 53, 80, 20 };

	*PRECT*/

	switch (message)
	{
	case WM_CREATE:
	{
		CreateWindowEx(0, TEXT("button"), TEXT("Заполнить"), WS_VISIBLE | WS_CHILD, 90, 10, 80, 20, hWnd, (HMENU)button1, 0, 0);
		CreateWindowEx(0, TEXT("button"), TEXT("Очистить"), WS_VISIBLE | WS_CHILD, 90, 53, 80, 20, hWnd, (HMENU)button2, 0, 0);
		hEditA = CreateWindowEx(0, TEXT("edit"), 0, WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 93, 80, 20, hWnd, (HMENU)edit1, 0, 0);
	}break;

	case WM_COMMAND:
	{
		if (wp == 1001)  		// нажата кнопка "заполнить" ?
		{
			SetWindowTextA(hEditA, bufi);
		}

		else if (wp == 1002)
		{
			SetWindowTextA(hEditA, bufg);


		}
	}
	break;

	case WM_CLOSE:
	{
		PostQuitMessage(0);
	}break;

	}
	return 0;
}
