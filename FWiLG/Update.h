#pragma once

namespace update
{
	Update()
	{
		bool kW = false, kA = false, kS = false, kD = false, kK = false, kL = false, kE = false;

		hpBar();
		coinsBar();
		bombsBar();

		while (hp > 0 && !WIN)
		{
			// day / night
			if (DN)
			{
				++dn;
				if (dn > 16660 * 30) DayNight();
			}

			xy.X = x;
			xy.Y = y;
			SetConsoleCursorPosition(hc, xy);

			// control
			if (!kW && GetKeyState('W') < 0 && world[x][y - 1] != 20 && (world[x][y - 1] < 176 || world[x][y - 1] > 178)) { kW = true; getch(); --y; UpdatePos(); }
			if (!kA && GetKeyState('A') < 0 && world[x - 1][y] != 20 && (world[x - 1][y] < 176 || world[x - 1][y] > 178)) { kA = true; getch(); --x; UpdatePos(); }
			if (!kS && GetKeyState('S') < 0 && world[x][y + 1] != 20 && (world[x][y + 1] < 176 || world[x][y + 1] > 178)) { kS = true; getch(); ++y; UpdatePos(); }
			if (!kD && GetKeyState('D') < 0 && world[x + 1][y] != 20 && (world[x + 1][y] < 176 || world[x + 1][y] > 178)) { kD = true; getch(); ++x; UpdatePos(); }

			if (!kK && GetKeyState('K') < 0) { kK = true; getch(); DayNight(); }
			if (!kL && GetKeyState('L') < 0) { kL = true; getch(); DN = !DN; }
			if (!kE && GetKeyState('E') < 0) { kE = true; getch(); Boom(); }
			// keys
			if (kW && GetKeyState('W') >= 0) kW = false;
			if (kA && GetKeyState('A') >= 0) kA = false;
			if (kS && GetKeyState('S') >= 0) kS = false;
			if (kD && GetKeyState('D') >= 0) kD = false;
			if (kK && GetKeyState('K') >= 0) kK = false;
			if (kL && GetKeyState('L') >= 0) kL = false;
			if (kE && GetKeyState('E') >= 0) kE = false;

			// @
			UpdateDog();

			// exit
			if (GetKeyState(VK_ESCAPE) < 0) { ex = true; getch(); break; }
		}

		if (!ex)
		{
			if (hp > 0)
			{
				xy.X = 45;
				xy.Y = Y;
				SetConsoleCursorPosition(hc, xy);
				printf("CONGRATULATE!!!");
				xy.X = 45;
				xy.Y = Y + 1;
				SetConsoleCursorPosition(hc, xy);
				printf("YOU WIN!!!");

				if (coins == maxCoins)
				{
					if (CheckLVL(tutor))
					{
						FILE* code = fopen("secret_tutor.txt", "w");
						fprintf(code, "Why did you do it?");
						fclose(code);
					}
					else if (CheckLVL(lvl0))
					{
						FILE* code = fopen("secret_lvl0.txt", "w");
						fprintf(code, "The code starts at the next level!");
						fclose(code);
					}
					else if (CheckLVL(lvl1))
					{
						FILE* code = fopen("secret_lvl1.txt", "w");
						fprintf(code, "R");
						fclose(code);
					}
					else if (CheckLVL(lvl2))
					{
						FILE* code = fopen("secret_lvl2.txt", "w");
						fprintf(code, "G");
						fclose(code);
					}
					else if (CheckLVL(lvl3))
					{
						FILE* code = fopen("secret_lvl3.txt", "w");
						fprintf(code, "B");
						fclose(code);
					}
					else if (CheckLVL(lvl4))
					{
						FILE* code = fopen("secret_lvl4.txt", "w");
						fprintf(code, "ABSOLUTE VICTORY!!!");
						fclose(code);
					}
				}
			}
			else
			{
				xy.X = 45;
				xy.Y = Y;
				SetConsoleCursorPosition(hc, xy);
				printf("CONGRATULATE!!!");
				xy.X = 45;
				xy.Y = Y + 1;
				SetConsoleCursorPosition(hc, xy);
				printf("YOU LOOOOOOOOSER!!!");
			}
		}
	}
}
