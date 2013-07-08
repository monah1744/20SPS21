#include "KWnd.h"


KWnd::KWnd(LPCTSTR windowName, 
		HINSTANCE hInst, 
		int cmdShow, 
		LRESULT (WINAPI *pWndProc)(HWND,UINT,WPARAM,LPARAM),
		LPCWSTR menuName,
		int x,
		int y,
		int width,
		int height,
		UINT classStyle,
		DWORD windowStyle,
		HWND hParent)
{
	TCHAR szClassName[]= TEXT("KWndClass");

	wc.cbSize	= sizeof (wc);
	wc.style	= classStyle;
	wc.lpfnWndProc	= pWndProc;
	wc.cbClsExtra	= 0;
	wc.cbWndExtra	= 0;
	wc.hInstance	= hInst;
	wc.hIcon	= LoadIcon (NULL, IDI_APPLICATION);
	wc.hCursor	= LoadCursor (NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName	= menuName;
	wc.lpszClassName	= szClassName;
	wc.hIconSm	= LoadIcon (NULL, IDI_APPLICATION);

	//--- Регистрируем класс окна ---
	if (!RegisterClassEx(&wc))
	{
		//char msg[100]="Не удалось зарегистрировать класс: ";
		//strcat(msg,TEXT(szClassName));
		MessageBox (NULL,TEXT("Не удалось зарегистрировать класс: "),TEXT("Ошибка"), MB_OK);
		return;
	}

	//--- Создаем окно ---
	hWnd = CreateWindow(szClassName, windowName, windowStyle, x, y, width, height, hParent, (HMENU) NULL, hInst, NULL);

	if (!hWnd)
	{
		//char text[100] = "Не удалось создать окно: ";
		//strcat (text, TEXT(windowName));
		MessageBox (NULL, TEXT("Не удалось создать окно: "), TEXT("Ошибка"), MB_OK);
		return;
	}

	//--- Показываем окно ---
	ShowWindow (hWnd, cmdShow);
}


KWnd::~KWnd()
{
}
