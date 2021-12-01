#pragma once
#include <windows.h>

using namespace std;

#define HEIGHT 26
#define WIDTH 35

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD ServerCoords = { 1, 2 };
COORD ClientCoords = { 2, 2 };
int ClientCoint = 0;
int ServerCoint = 0;

enum Keys
{
	K_LEFT = 77,
	K_RIGHT = 75,
	K_DOWN = 72,
	K_UP = 80
};

enum Objects
{
	HW = 196, // Horizontal wall
	VW = 179, // Vertical wall

	LTA =195, // Left Top Angle
	RTA = 191, // Right Top Angle

	LBA = 195, // Left Bottom Angle
	RBA = 195, // Right Bottom Angle

	O = 0, // Space
	M = 3,
	CL = 1,
	CS = 2,
};

int FirstMap[HEIGHT][WIDTH] =
{
{ LTA,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,RTA },
{ VW,CL,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,CS,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
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
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
{ LBA,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,RBA },
};

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
							if (FirstMap[i][j] == CS)
							{
								cout << endl << "SERVER WINS!";
							}
							else
							{
								cout << endl << "CLIENT WINS!";
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

void MovementCharacters(void* p)
{
	SOCKET local = *((SOCKET*)p);
	static int coins = 0;
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
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] != CL &&
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				ServerCoords.X--;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;

		case K_LEFT:
			if (FirstMap[ServerCoords.Y][ServerCoords.X + 1] != HW &&
				FirstMap[ServerCoords.Y][ServerCoords.X + 1] != CL &&
				FirstMap[ServerCoords.Y][ServerCoords.X + 1] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				ServerCoords.X++;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;

		case K_UP:
			if (FirstMap[ServerCoords.Y + 1][ServerCoords.X] != HW &&
				FirstMap[ServerCoords.Y + 1][ServerCoords.X] != CL &&
				FirstMap[ServerCoords.Y + 1][ServerCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				ServerCoords.Y++;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;

		case K_DOWN:
			if (FirstMap[ServerCoords.Y - 1][ServerCoords.X] != HW &&
				FirstMap[ServerCoords.Y - 1][ServerCoords.X] != CL &&
				FirstMap[ServerCoords.Y - 1][ServerCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				ServerCoords.Y--;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;
		}
		COORD money = { 0, 55 };
		SetConsoleCursorPosition(h, money);
		SetConsoleTextAttribute(h, 12);
		cout << coins;
		char crd[3];
		crd[0] = ServerCoords.X;
		crd[1] = ServerCoords.Y;
		crd[2] = coins;
		ServerCoint = coins;
		SetConsoleCursorPosition(h, ServerCoords);
		SetConsoleTextAttribute(h, 9);
		cout << (char)1;
		SetConsoleCursorPosition(h, ClientCoords);
		SetConsoleTextAttribute(h, 12);
		cout << (char)1;

		send(local, crd, 3, 0);
	}
}

void Drawmap()
{
	char ASCII[256];
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			if (FirstMap[i][j] == LTA)
			{
				ASCII[LTA] = LTA;
				cout << ASCII[LTA];
			}
			else if (FirstMap[i][j] == HW)
			{
				ASCII[HW] = HW;
				cout << ASCII[HW];
			}
			else if (FirstMap[i][j] == VW)
			{
				ASCII[VW] = VW;
				cout << ASCII[VW];
			}
			else if (FirstMap[i][j] == RTA)
			{
				ASCII[RTA] = RTA;
				cout << ASCII[RTA];
			}
			else if (FirstMap[i][j] == LBA)
			{
				ASCII[LBA] = LBA;
				cout << ASCII[LBA];
			}
			else if (FirstMap[i][j] == RBA)
			{
				ASCII[RBA] = RBA;
				cout << ASCII[RBA];
			}
			else if (FirstMap[i][j] == CL)
			{
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(h, ClientCoords);
				SetConsoleTextAttribute(h, 12);
				ASCII[CL] = CL;
				cout << ASCII[CL];
				SetConsoleTextAttribute(h, 10);
			}
			else if (FirstMap[i][j] == CS)
			{
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				ASCII[CS] = CS;
				cout << ASCII[CS];
				SetConsoleTextAttribute(h, 10);
			}
			if (FirstMap[i][j] == O)
			{
				cout << ' ';
			}
		}
		cout << endl;
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
			FirstMap[y][x] == M;
			i--;
		}
	}
}
void SendMap(SOCKET temp)
{
	char mas[20 * 20];

	int k = 0;
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			mas[k] = FirstMap[i][j];
			k++;
		}
	}

	send(temp, mas, 20 * 20, 0);
}
DWORD WINAPI Timer(void* p)
{
	SOCKET s = *(SOCKET*)(p);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD timer = { 100, 100 };
	int time = 30;
	while (true)
	{
		SetConsoleCursorPosition(h, timer);
		SetConsoleTextAttribute(h, 6);
		cout << "  ";
		SetConsoleCursorPosition(h, timer);
		cout << time;
		Sleep(1000);
		time--;
		if (time < 0)
		{
			break;
		}
	}
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
		SetConsoleCursorPosition(h, ClientCoords);
		cout << " ";
		if (recv(s, message, 2, 0))
		{
			ClientCoords.X = message[0];
			ClientCoords.Y = message[1];
			ClientCoint = message[2];
		}
		SetConsoleCursorPosition(h, ClientCoords);
		SetConsoleTextAttribute(h, 12);
		cout << (char)1;
	}
}

DWORD WINAPI Sender(void* p)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, ServerCoords);
	SetConsoleTextAttribute(h, 9);

	MovementCharacters(p);

	return 0;
}