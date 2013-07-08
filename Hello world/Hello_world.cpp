#include <Windows.h>
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL,TEXT("Hello, Win32 world"), TEXT("Hello from Message Box"), MB_OK);
	return 0;
}