/* <<=====>> Find Way in Logic Game <<=====>> */
#include<stdio.h>
#include<conio.h>
#include<vector>
#include<windows.h>
#include"fwilg.h"
#include"other.h"
#include"LevelEdit.h"
#include"Start.h"
#include"Update.h"
using namespace leveledit;
using namespace start;
using namespace update;

int main()
{
	typedef UINT(CALLBACK* TImportFunc)(HANDLE, UINT);
	TImportFunc SetConsoleFont = (TImportFunc)GetProcAddress(GetModuleHandle("kernel32.dll"), "SetConsoleFont");
	SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	CONSOLE_FONT_INFOEX fi;

	fi.cbSize = sizeof(fi);
	GetCurrentConsoleFontEx(hc, FALSE, &fi);
	fi.dwFontSize.X = 12;
	fi.dwFontSize.Y = 16;
	SetCurrentConsoleFontEx(hc, FALSE, &fi);

	SetWindowPos(hw, HWND_TOP, -5, 0, 0, 0, NULL);

	system("title FWiLG");
	system("mode con cols=113 lines=43");

	for (int i = 0; i < X + 2; ++i) for (int j = 0; j < Y + 2; ++j) world[i][j] = 0;

	cci.bVisible = true;
	SetCursorSize(100);

	Start();

	if (!ex) if (play) Update(); else LevelEdit();

	if (!ex)
	{
		xy.X = 0;
		xy.Y = Y + 2;
		SetConsoleCursorPosition(hc, xy);
		system("pause");
	}
	return 0;
}
