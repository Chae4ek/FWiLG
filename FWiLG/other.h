#pragma once
using namespace fwilg;

namespace other
{
	medBar()
	{
		xy.X = 1;
		xy.Y = Y;
		SetConsoleCursorPosition(hc, xy);
		printf("Medkits: %d    ", medk);
	}
	mcBar()
	{
		xy.X = 1;
		xy.Y = Y + 1;
		SetConsoleCursorPosition(hc, xy);
		printf("Coins: %d    ", maxCoins);
	}
	mbBar()
	{
		xy.X = 18;
		xy.Y = Y;
		SetConsoleCursorPosition(hc, xy);
		printf("Bombs: %d    ", maxBombs);
	}

	UpdateLE(int clr)
	{
		int x = mx, y = my;
		if (x <= 0 || y <= 0 || x >= X - 1 || y >= Y - 2) return 0;

		if (world[x][y] == 4 && clr != 4) { --medk; medBar(); }
		else
			if (world[x][y] == 254 && clr != 254) { --maxCoins; mcBar(); }
			else
				if (world[x][y] == '$' && clr != '$') { --maxBombs; mbBar(); }

		if (clr == 4 && world[x][y] != 4) { ++medk; medBar(); }
		else
			if (clr == 254 && world[x][y] != 254) { ++maxCoins; mcBar(); }
			else
				if (clr == '$' && world[x][y] != '$') { ++maxBombs; mbBar(); }

		xy.X = x;
		xy.Y = y;
		SetConsoleCursorPosition(hc, xy);
		printf("%c", clr);
		world[x][y] = clr;
	}

	EnterCode()
	{
		system("cls");

		char cc[50];
		printf("\n Code: ");
		fflush(stdin);
		while (kbhit()) getch();
		scanf("%[^\n]", &cc);

		if (!strcmp(cc, "RGB"))
		{
			FILE* file = fopen("RGB", "w");

			int p = 0;
			for (int j = 0; j < Y - 3; ++j)
			{
				for (int i = 0; i < X - 2; ++i, ++p)
				{
					fprintf(file, "%d ", Slvl[p]);
				}
				fprintf(file, "\n");
			}

			fclose(file);
		}
	}

	bool CheckLVL(int a[])
	{
		for (int i = 0; i < secret.size(); ++i)
		{
			if (secret[i] != a[i]) return false;
		}
		return true;
	}
}
