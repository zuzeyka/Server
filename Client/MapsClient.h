#pragma once
#include <windows.h>

using namespace std;

#define HEIGHT 26
#define WIDTH 35

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD ServerCoords = { 2, 1 };
COORD ClientCoords = { 1, 1 };
int ServerCoins = 0;
int ClientCoins = 0;
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

bool Timer()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD timer = { 40, 3 };
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
	return 1;
}

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
	thread = 0;
	system("cls");
	if (ClientCoins < ServerCoins)
	{
		cout << "Server coins - " << ServerCoins << " Client coins - " << ClientCoins << " SERVER WINS!";
	}
	else
	{
		cout << "Server coins - " << ServerCoins << " Client coins - " << ClientCoins << "CLIENT WINS!";
	}
	Sleep(3000);
	exit(0);
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
				if (FirstMap[ClientCoords.Y][ClientCoords.X - 1] == M)
				{
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
					ClientCoins++;
				}
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
				if (FirstMap[ClientCoords.Y][ClientCoords.X + 1] == M)
				{
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
					ClientCoins++;
				}
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
				if (FirstMap[ClientCoords.Y + 1][ClientCoords.X] == M)
				{
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
					ClientCoins++;
				}
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
				if (FirstMap[ClientCoords.Y - 1][ClientCoords.X] == M)
				{
					FirstMap[ClientCoords.Y][ClientCoords.X] = O;
					ClientCoins++;
				}
				FirstMap[ClientCoords.Y - 1][ClientCoords.X] = CL;
				ClientCoords.Y--;
				DrawPers(CL);
			}
			break;
		}


		char crd[3];
		crd[0] = ClientCoords.X;
		crd[1] = ClientCoords.Y;
		crd[2] = ClientCoins;

		DrawPers(CS);
		DrawPers(CL);

		send(local, crd, 3, 0);

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
			else if (FirstMap[i][j] == M)
			{
				SetConsoleTextAttribute(h, 13);
			}
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
	char message[3];
	while (true)
	{
		
		if (recv(s, message, 3, 0))
		{
			SetConsoleCursorPosition(h, ServerCoords);
			cout << " ";
			FirstMap[ServerCoords.Y][ServerCoords.X] = O;
			ServerCoords.X = message[0];
			ServerCoords.Y = message[1];
			ServerCoins = message[2];
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