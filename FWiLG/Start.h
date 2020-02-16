#pragma once

namespace start
{
	Start()
	{
		printf("Find Way in Logic Game v0.0.1\n\n\n Oh! Hello!\n\n Press [SPACE] to start or press [F] to make the level!\n\n Press [ESCAPE] to exit!\n\n\n\n Press [ENTER] to enter a code!");
		char c;

		while (true)
		{
			c = getch();
			if (c == VK_SPACE) break;
			if (c == 'f' || c == 'F') { play = false; break; }
			if (c == VK_ESCAPE) { ex = true; return 0; }
			if (c == 13) { ex = true; EnterCode(); return 0; }
		}

		system("cls");

		char save[50];
		printf("\n Level name: ");
		fflush(stdin);
		while (kbhit()) getch();
		scanf("%[^\n]", &save);

		system("cls");

		xy.X = 0;
		xy.Y = 0;
		SetConsoleCursorPosition(hc, xy);
		for (int i = 0; i < X; ++i) { printf("%c", 178); world[i][0] = 178; }
		xy.Y = Y - 2;
		SetConsoleCursorPosition(hc, xy);
		for (int i = 0; i < X; ++i) { printf("%c", 178); world[i][Y - 2] = 178; }
		xy.X = 0;
		for (int i = 0; i < Y - 3; ++i)
		{
			xy.Y = i + 1;
			SetConsoleCursorPosition(hc, xy);
			printf("%c", 178);
			world[0][i + 1] = 178;
		}
		xy.X = X - 1;
		for (int i = 0; i < Y - 3; ++i)
		{
			xy.Y = i + 1;
			SetConsoleCursorPosition(hc, xy);
			printf("%c", 178);
			world[X - 1][i + 1] = 178;
		}

		FILE* file = fopen(save, "r");

		int s;
		for (int j = 1; j < Y - 2; ++j)
		{
			xy.X = 1;
			xy.Y = j;
			SetConsoleCursorPosition(hc, xy);
			for (int i = 1; i < X - 1; ++i)
			{
				if (file) fscanf(file, "%d", &s); else s = 0;
				secret.push_back(s);
				printf("%c", s);
				if (s == '@') AddDog(i, j);
				world[i][j] = s;
				if (world[i][j] == 254) ++maxCoins; else
					if (world[i][j] == 4) ++medk; else
						if (world[i][j] == '$') ++maxBombs;
			}
		}
		fscanf(file, "%d", &dif);
		xy.X = 80;
		xy.Y = Y + 1;
		SetConsoleCursorPosition(hc, xy);
		printf("Difficulty: ");
		if (dif == 1) printf("Easy"); else
			if (dif == 2) printf("Normal"); else
				if (dif == 3) printf("Hard"); else printf("Unknown");

		fclose(file);
	}
}
