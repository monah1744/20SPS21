#include <windows.h>
#include <time.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassWindow[] = TEXT("Каркасное приложение");	

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);	
	wcl.style = CS_HREDRAW | CS_VREDRAW;	
	wcl.lpfnWndProc = WindowProc;	
	wcl.cbClsExtra = 0;	
	wcl.cbWndExtra = 0; 	
	wcl.hInstance = hInst;	
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	
	wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH); 
	wcl.lpszMenuName = NULL;	
	wcl.lpszClassName = szClassWindow;	
	wcl.hIconSm = NULL;
	
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, 
		TEXT("Практическое задание"), WS_OVERLAPPEDWINDOW,	
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, 
	TEXT("Откройте, пожалуйста, \"Калькулятор\", и нажмите <CTRL>"), 	TEXT("Практическое задание"), 
	MB_OK | MB_ICONINFORMATION);

		while(GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);	
		DispatchMessage(&lpMsg);	
	}
	return lpMsg.wParam;
}

BOOL CALLBACK EnumChildProc (HWND hW, LPARAM lParam)
{
	ShowWindow(hW, SW_HIDE);
	return 0;
}

VOID CALLBACK TimerProc (HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	HWND h = FindWindow(TEXT("SciCalc"), TEXT("Калькулятор"));
	if(!h)
		MessageBox(hWnd,TEXT("Необходимо открыть \"Калькулятор\""),TEXT("Ошибка!!!"), MB_OK | MB_ICONSTOP);
	else
		// начинаем перечисление дочерних окон "Калькулятора"	
		EnumChildWindows(h, EnumChildProc, (LPARAM) hWnd);
}

LRESULT CALLBACK WindowProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	static time_t t;
	switch(message)
	{
		case WM_DESTROY: 
			PostQuitMessage(0);
			break;
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_RETURN:
					MessageBox(hWnd,TEXT("Процесс начат !"), TEXT(" Start "), MB_OK);
					SetTimer (hWnd,1,1000,TimerProc);
					break;
				case VK_ESCAPE:
					KillTimer(hWnd,1);
					MessageBox(hWnd,TEXT("Процесс окончен !"), TEXT(" Stop "), MB_OK);
					break;
			}
			break;	
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}