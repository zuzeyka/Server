#pragma once
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

#define HEIGHT 26
#define WIDTH 35

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD ServerCoords = { 2, 1 };
COORD ClientCoords = { 1, 1 };
bool thread = 1;

enum Keys
{
	K_LEFT = 77,
	K_RIGHT = 75,
	K_DOWN = 72,
	K_UP = 80
};

enum Objects
{
	HW = 42, // Horizontal wall
	VW = 42, // Vertical wall

	LTA = 42, // Left Top Angle
	RTA = 42, // Right Top Angle

	LBA = 42, // Left Bottom Angle
	RBA = 42, // Right Bottom Angle

	O = 32, // Space
	F = 5,
	CL = 1,
	CS = 2,
	M = 3
};

char FirstMap[HEIGHT][WIDTH] = {
{ LTA,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,RTA },
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
{ LBA,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,RBA },
};
void DrawPers(int who)
{
	if (who == CL)
	{
		SetConsoleCursorPosition(h, ClientCoords);
		SetConsoleTextAttribute(h, 11);
		cout << (char)1;
	}
	else
	{
		SetConsoleCursorPosition(h, ServerCoords);
		SetConsoleTextAttribute(h, 14);
		cout << (char)1;
	}
}
void Check()
{
	while (true)
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (FirstMap[i][j] == CL or FirstMap[i][j] == CS)
				{
					if (i >= HEIGHT - 5)
					{
						if (j >= WIDTH - 2)
						{
							thread = 0;
							system("cls");
							if (FirstMap[i][j] == CS)
							{
								cout << "SERVER WINS!";
							}
							else
							{
								cout << "CLIENT WINS!";
							}
							Sleep(3000);
							exit(0);
						}
					}
				}
			}
		}
	}
}

DWORD WINAPI MovementCharacters(void* p)
{
	SOCKET local = *((SOCKET*)p);
	while (true)
	{
		int direct = _getch();
		if (direct == 224)
		{
			direct = _getch();
		}
		switch (direct)
		{
		case K_RIGHT:

			if (FirstMap[ServerCoords.Y][ServerCoords.X - 1] != HW &&
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] = CS;
				ServerCoords.X--;
				DrawPers(CS);
			}
			break;

		case K_LEFT:
			if (FirstMap[ServerCoords.Y][ServerCoords.X + 1] != HW &&
				FirstMap[ServerCoords.Y][ServerCoords.X + 1] != CL &&
				FirstMap[ServerCoords.Y][ServerCoords.X + 1] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				FirstMap[ServerCoords.Y][ServerCoords.X + 1] = CS;
				ServerCoords.X++;
				DrawPers(CS);
			}
			break;

		case K_UP:
			if (FirstMap[ServerCoords.Y + 1][ServerCoords.X] != HW &&
				FirstMap[ServerCoords.Y + 1][ServerCoords.X] != CL &&
				FirstMap[ServerCoords.Y + 1][ServerCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				FirstMap[ServerCoords.Y + 1][ServerCoords.X] = CS;
				ServerCoords.Y++;
				DrawPers(CS);
			}
			break;

		case K_DOWN:
			if (FirstMap[ServerCoords.Y - 1][ServerCoords.X] != HW &&
				FirstMap[ServerCoords.Y - 1][ServerCoords.X] != CL &&
				FirstMap[ServerCoords.Y - 1][ServerCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				FirstMap[ServerCoords.Y - 1][ServerCoords.X] = CS;
				ServerCoords.Y--;
				DrawPers(CS);
			}
			break;
		}

		char crd[2];
		crd[0] = ServerCoords.X;
		crd[1] = ServerCoords.Y;

	/*	SetConsoleCursorPosition(h, ServerCoords);
		SetConsoleTextAttribute(h, 9);
		cout << (char)1;*/
		DrawPers(CS);
		/*SetConsoleCursorPosition(h, ClientCoords);
		SetConsoleTextAttribute(h, 12);
		cout << (char)1;*/
		DrawPers(CL);

		send(local, crd, 2, 0);
		if (!thread)
		{
			Sleep(3000);
			exit(0);
		}
	}

}
void GenerationCoins()
{
	int count_coin = 20;
	for (int i = count_coin; i > 0;)
	{
		int y = rand() % HEIGHT;
		int x = rand() % WIDTH;
		if (FirstMap[y][x] == O)
		{
			FirstMap[y][x] = M;
			i--;
		}
	}
}
void Drawmap()
{
	//GenerationCoins();
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			if (FirstMap[i][j] == F)
			{
				SetConsoleTextAttribute(h, 11);
			}
			/*else if (FirstMap[i][j] == M)
			{
				SetConsoleTextAttribute(h, 13);
			}*/
			cout << FirstMap[i][j];
			SetConsoleTextAttribute(h, 5);
		}
		cout << endl;
	}
}
void SendMap(SOCKET temp)
{
	char mas[HEIGHT * WIDTH];

	int k = 0;
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			mas[k] = (char)FirstMap[j][i];
			k++;
		}
	}
	send(temp, mas, HEIGHT * WIDTH, 0);
}
DWORD WINAPI rec(void* p)
{
	SOCKET s = *(SOCKET*)(p);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, ClientCoords);
	SetConsoleTextAttribute(h, 12);
	char message[2];
	while (true)
	{
		
		if (recv(s, message, 2, 0))
		{
			SetConsoleCursorPosition(h, ClientCoords);
			cout << " ";
			FirstMap[ClientCoords.Y][ClientCoords.X] = O;
			ClientCoords.X = message[0];
			ClientCoords.Y = message[1];
			FirstMap[ClientCoords.Y][ClientCoords.X] = CL;
		}
		//SetConsoleCursorPosition(h, ClientCoords);
		//SetConsoleTextAttribute(h, 12);
		//cout << (char)1;
		DrawPers(CL);
		if (!thread)
		{
			Sleep(3000);
			exit(0);
		}
	}
}

//DWORD WINAPI Sender(void* p)
//{
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(h, ServerCoords);
//	SetConsoleTextAttribute(h, 9);
//
//	MovementCharacters(p);
//
//	return 0;
//}