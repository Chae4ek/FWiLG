#pragma once
using namespace other;

namespace leveledit
{
	LevelEdit()
	{
		POINT pt;
		RECT rt;

		bool k_ = false, mPos = true;
		char c;

		medBar();
		mcBar();
		mbBar();

		while (true)
		{
			// mouse tracking
			if (mPos)
			{
				GetCursorPos(&pt);
				GetWindowRect(hw, &rt);
				mx = (pt.x - rt.left - 10) / 12;
				my = (pt.y - rt.top - 32) / 16;
				xy.X = mx;
				xy.Y = my;
				SetConsoleCursorPosition(hc, xy);
			}

			// blocks
			if (mx > 0 && my > 0 && mx < X - 1 && my < Y - 2)
			{
				// text
				if (!k_ && GetKeyState(13) < 0) { k_ = true; mPos = !mPos; fflush(stdin); while (kbhit()) getch(); }
				if (!mPos)
				{
					c = getch();
					if ((c >= 65 && c <= 91) || (c >= 97 && c <= 123) || (c >= 48 && c <= 57) || c == 32 || c == 93 || c == 8 || c == 40 || c == 41 || c == 125)
					{
						if (c == 8)
						{
							xy.X = --mx;
							xy.Y = my;
							SetConsoleCursorPosition(hc, xy);
							printf("%c", 0);
							world[mx][my] = 0;
							SetConsoleCursorPosition(hc, xy);
							--mx;
						}
						else if (c == 32) { printf("%c", 0); world[mx][my] = 0; }
						else { printf("%c", c); world[mx][my] = c; }
						++mx;
					}
					else if (c == 13) { k_ = true; mPos = !mPos; fflush(stdin); while (kbhit()) getch(); }
				}
				else
				{
					// control
					if (GetKeyState('1') < 0) UpdateLE(176);
					if (GetKeyState('2') < 0) UpdateLE(177);
					if (GetKeyState('3') < 0) UpdateLE(178);
					if (GetKeyState('4') < 0) UpdateLE(20);
					if (GetKeyState(VK_TAB) < 0) UpdateLE(0);

					if (GetKeyState('Q') < 0) UpdateLE(219);
					if (GetKeyState('W') < 0) UpdateLE(254);
					if (GetKeyState('E') < 0) UpdateLE(253);
					if (GetKeyState('R') < 0) UpdateLE(21);
					if (GetKeyState('S') < 0) UpdateLE('#');
					if (GetKeyState('A') < 0) UpdateLE(4);
					if (GetKeyState('D') < 0) UpdateLE('@');
					if (GetKeyState('F') < 0) UpdateLE('$');
					if (GetKeyState('T') < 0) UpdateLE('+');
				}
			}
			else mPos = true;

			if (k_ && GetKeyState(13) >= 0) k_ = false;
			// save & exit
			if (mPos && GetKeyState(VK_ESCAPE) < 0) { ex = true; getch(); break; }
		}

		// saving
		char save[50] = { 0 };
		xy.X = 33;
		xy.Y = Y;
		SetConsoleCursorPosition(hc, xy);
		printf("Level name: ");
		fflush(stdin);
		while (kbhit()) getch();
		scanf("%[^\n]", &save);

		FILE* file = fopen(save, "w");

		for (int j = 1; j < Y - 2; ++j)
		{
			for (int i = 1; i < X - 1; ++i)
			{
				fprintf(file, "%d ", world[i][j]);
			}
			fprintf(file, "\n");
		}
		if (dif >= 1 && dif <= 3) fprintf(file, "%d", dif);

		fclose(file);
	}
}
