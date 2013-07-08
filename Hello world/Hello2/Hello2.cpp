#include <Windows.h>
#include "KWnd.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	KWnd mainWnd(L"Hello2 Application", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//--------------------------------------------------------

LRESULT CALLBACK WndProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	int userReply;
	switch (uMsg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		
		GetClientRect(hWnd, &rect);
		DrawText(hDC,TEXT("Hello1 World!!!"), -1, &rect, DT_SINGLELINE| DT_CENTER| DT_VCENTER);
		
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		userReply = MessageBox(hWnd,TEXT("Вы уверены, что хотите выйти ?"),TEXT(""),MB_YESNO | MB_ICONQUESTION);
		if (IDYES==userReply)
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc (hWnd, uMsg, wParam, lParam);
	}

	return 0;
}