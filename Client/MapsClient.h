#pragma once
#include <windows.h>

using namespace std;

#define HEIGHT 26
#define WIDTH 35

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD ServerCoords = { 2, 1 };
COORD ClientCoords = { 1, 1 };
int ClientCoins = 0;
int ServerCoins = 0;
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
	HW = 196, // Horizontal wall
	VW = 179, // Vertical wall

	LTA = 218, // Left Top Angle
	RTA = 191, // Right Top Angle

	LBA = 192, // Left Bottom Angle
	RBA = 217, // Right Bottom Angle

	O = 0, // Space
	F = 5,
	CL = 1,
	CS = 2,
	M = 3
};

int FirstMap[HEIGHT][WIDTH];
//=
//{
//{ LTA,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,RTA },
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,VW},
//{ VW,O,O,O,O,O,O,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
//{ VW,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,F,VW},
//{ LBA,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,HW,RBA },
//};

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
	int coins = 0;
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

			if (FirstMap[ClientCoords.Y][ClientCoords.X - 1] != HW &&
				FirstMap[ClientCoords.Y][ClientCoords.X - 1] != CS &&
				FirstMap[ClientCoords.Y][ClientCoords.X - 1] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				FirstMap[ClientCoords.Y][ClientCoords.X - 1] = CL;
				ClientCoords.X--;
				SetConsoleCursorPosition(h, ClientCoords);
				SetConsoleTextAttribute(h, 12);
				cout << (char)1;
			}
			break;

		case K_LEFT:
			if (FirstMap[ClientCoords.Y][ClientCoords.X + 1] != HW &&
				FirstMap[ClientCoords.Y][ClientCoords.X + 1] != CS &&
				FirstMap[ClientCoords.Y][ClientCoords.X + 1] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				FirstMap[ClientCoords.Y][ClientCoords.X + 1] = CL;
				ClientCoords.X++;
				SetConsoleCursorPosition(h, ClientCoords);
				SetConsoleTextAttribute(h, 12);
				cout << (char)1;
			}
			break;

		case K_UP:
			if (FirstMap[ClientCoords.Y + 1][ClientCoords.X] != HW &&
				FirstMap[ClientCoords.Y + 1][ClientCoords.X] != CS &&
				FirstMap[ClientCoords.Y + 1][ClientCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				FirstMap[ClientCoords.Y + 1][ClientCoords.X] = CL;
				ClientCoords.Y++;
				SetConsoleCursorPosition(h, ClientCoords);
				SetConsoleTextAttribute(h, 12);
				cout << (char)1;
			}
			break;

		case K_DOWN:
			if (FirstMap[ClientCoords.Y - 1][ClientCoords.X] != HW &&
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] != CS &&
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				if (FirstMap[ClientCoords.Y][ClientCoords.X] == M)
				{
					coins++;
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				}
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] = CL;
				ClientCoords.Y--;
				SetConsoleCursorPosition(h, ClientCoords);
				SetConsoleTextAttribute(h, 12);
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
		ServerCoins = coins;

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

void Drawmap()
{
	char ASCII[256];
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			if (FirstMap[i][j] == '1')
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
			else if (FirstMap[i][j] == F)
			{
				SetConsoleTextAttribute(h, 14);
				ASCII[F] = F;
				cout << ASCII[F];
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

DWORD WINAPI rec(void* p)
{
	SOCKET s = *(SOCKET*)(p);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, ServerCoords);
	SetConsoleTextAttribute(h, 9);
	char message[2];
	while (true)
	{
		
		if (recv(s, message, 2, 0))
		{
			SetConsoleCursorPosition(h, ServerCoords);
			cout << " ";
			ServerCoords.X = message[0];
			ServerCoords.Y = message[1];
			FirstMap[ClientCoords.Y][ClientCoords.X] = CS;
		}
		SetConsoleCursorPosition(h, ServerCoords);
		SetConsoleTextAttribute(h, 9);
		cout << (char)2;
		if (!thread)
		{
			Sleep(3000);
			exit(0);
		}
		//cout << ServerCoords.Y;
		//Sleep(INFINITE);
	}
}
void recMap(SOCKET temp)
{
	char mas[HEIGHT * WIDTH];
	int k = 0;
	//AnsiToOem(mas, mas);
	recv(temp, mas, HEIGHT * WIDTH, 0);
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			FirstMap[i][j] = (int)mas[k];
			k++;
		}
	}
}
//
//DWORD WINAPI Sender(void* p)
//{
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(h, ClientCoords);
//	SetConsoleTextAttribute(h, 12);
//
//	MovementCharacters(p);
//
//	return 0;
//}