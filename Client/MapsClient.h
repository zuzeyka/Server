#pragma once
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

	O = 10, // Space
	F = 5,
	CL = 1,
	CS = 2,
	M = 3,
};

char FirstMap[HEIGHT][WIDTH] = {};

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

			if (FirstMap[ClientCoords.Y][ClientCoords.X - 1] != HW &&
				FirstMap[ClientCoords.Y][ClientCoords.X - 1] != CS &&
				FirstMap[ClientCoords.Y][ClientCoords.X - 1] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				FirstMap[ClientCoords.Y][ClientCoords.X - 1] = CL;
				ClientCoords.X--;
				DrawPers(CL);
			}
			break;

		case K_LEFT:
			if (FirstMap[ClientCoords.Y][ClientCoords.X + 1] != HW &&
				FirstMap[ClientCoords.Y][ClientCoords.X + 1] != CS &&
				FirstMap[ClientCoords.Y][ClientCoords.X + 1] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				FirstMap[ClientCoords.Y][ClientCoords.X + 1] = CL;
				ClientCoords.X++;
				DrawPers(CL);
			}
			break;

		case K_UP:
			if (FirstMap[ClientCoords.Y + 1][ClientCoords.X] != HW &&
				FirstMap[ClientCoords.Y + 1][ClientCoords.X] != CS &&
				FirstMap[ClientCoords.Y + 1][ClientCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				FirstMap[ClientCoords.Y + 1][ClientCoords.X] = CL;
				ClientCoords.Y++;
				DrawPers(CL);
			}
			break;

		case K_DOWN:
			if (FirstMap[ClientCoords.Y - 1][ClientCoords.X] != HW &&
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] != CS &&
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] != VW)
			{
				SetConsoleCursorPosition(h, ClientCoords);
				cout << " ";
				FirstMap[ClientCoords.Y][ClientCoords.X] = O;
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] = CL;
				ClientCoords.Y--;
				DrawPers(CL);
			}
			break;
		}


		char crd[2];
		crd[0] = ClientCoords.X;
		crd[1] = ClientCoords.Y;

		DrawPers(CS);
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
			FirstMap[ServerCoords.Y][ServerCoords.X] = O;
			ServerCoords.X = message[0];
			ServerCoords.Y = message[1];
			FirstMap[ServerCoords.Y][ServerCoords.X] = CS;
		}
		DrawPers(CS);

		if (!thread)
		{
			Sleep(3000);
			exit(0);
		}
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
			FirstMap[i][j] = mas[k];
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