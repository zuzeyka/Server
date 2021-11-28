#pragma once
#include <windows.h>

using namespace std;

#define HEIGHT 26
#define WIDTH 35

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD ServerCoords = { 1, 2 };
COORD ClientCoords = { 2, 2 };

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
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				ServerCoords.X--;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;

		case K_LEFT:
			if (FirstMap[ServerCoords.Y][ServerCoords.X + 1] != HW &&
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] != CL &&
				FirstMap[ServerCoords.Y][ServerCoords.X + 1] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				ServerCoords.X++;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;

		case K_UP:
			if (FirstMap[ServerCoords.Y + 1][ServerCoords.X] != HW &&
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] != CL &&
				FirstMap[ServerCoords.Y + 1][ServerCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				ServerCoords.Y++;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;

		case K_DOWN:
			if (FirstMap[ServerCoords.Y - 1][ServerCoords.X] != HW &&
				FirstMap[ServerCoords.Y][ServerCoords.X - 1] != CL &&
				FirstMap[ServerCoords.Y - 1][ServerCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ServerCoords);
				cout << " ";
				FirstMap[ServerCoords.Y][ServerCoords.X] = O;
				ServerCoords.Y--;
				FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
				SetConsoleCursorPosition(h, ServerCoords);
				SetConsoleTextAttribute(h, 9);
				cout << (char)1;
			}
			break;
		}
	}
	char crd[2];
	crd[0] = ServerCoords.X;
	crd[1] = ServerCoords.Y;

	SetConsoleCursorPosition(h, ServerCoords);
	SetConsoleTextAttribute(h, 12);
	cout << (char)1;

	send(local, crd, 2, 0);
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
	SetConsoleCursorPosition(h, ClientCoords);
	SetConsoleTextAttribute(h, 12);

	while (true)
	{
		char message[2];

		if (recv(s, message, 2, 0))
		{
			SetConsoleCursorPosition(h, ClientCoords);
			cout << " ";
			ClientCoords.X = message[0];
			ClientCoords.Y = message[1];
			SetConsoleCursorPosition(h, ClientCoords);
			SetConsoleTextAttribute(h, 12);
			cout << (char)1;
		}
	}
}

DWORD WINAPI Sender(void* p)
{
	SOCKET local = *((SOCKET*)p);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, ServerCoords);
	SetConsoleTextAttribute(h, 9);

	MovementCharacters(p);

	return 0;
}