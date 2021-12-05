// https://docs.microsoft.com/en-us/windows/win32/winsock/complete-client-code

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
// #include <winsock2.h>
#include <ws2tcpip.h>
#include <conio.h>
#include "MapsClient.h"
using namespace std;

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

#define PAUSE 50

// SOCKET ConnectSocket = INVALID_SOCKET;

int main(int argc, char** argv) // ��� ������� ��� ������� ����� ����� ������� ����� ��������� ��������� ������
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	//setlocale(0, " ");
	system("title CLIENT SIDE");
	cout << "������� ������� �������!\n";
	Sleep(PAUSE);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Initialize Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		cout << "WSAStartup failed with error: " << iResult << "\n";
		return 11;
	}
	else {
		cout << "����������� Winsock.dll ������ �������!\n";
		Sleep(PAUSE);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	const char* ip = "localhost"; // �� ���������, ��� ����������, � ������, � ������, ����������� �� ����� � ��� �� ������

	//iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result); // �����������������, ���� ����� ����� ������ ��� ������� �� ��������� ������
	addrinfo* result = NULL;
	iResult = getaddrinfo(ip, DEFAULT_PORT, &hints, &result);

	if (iResult != 0) {
		cout << "getaddrinfo failed with error: " << iResult << "\n";
		WSACleanup();
		return 12;
	}
	else {
		cout << "��������� ������ � ����� ������� ������ �������!\n";
		Sleep(PAUSE);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Attempt to connect to an address until one succeeds

	SOCKET ConnectSocket = INVALID_SOCKET;

	for (addrinfo* ptr = result; ptr != NULL; ptr = ptr->ai_next) { // �������� ����� ���� ���������, ������� �� �������� ����

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

		if (ConnectSocket == INVALID_SOCKET) {
			cout << "socket failed with error: " << WSAGetLastError() << "\n";
			WSACleanup();
			return 13;
		}

		// Connect to server
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}

		cout << "�������� ������ �� ������� ������ �������!\n";
		Sleep(PAUSE);

		break;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		cout << "���������� ������������ � �������. ���������, ��� ������� ������� �������!\n";
		WSACleanup();
		return 14;
	}
	else {
		cout << "����������� � ������� ������ �������!\n";
		Sleep(PAUSE);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	system("cls");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	recMap(ConnectSocket);
	Drawmap();
	//Drawmap();

	DrawPers(CS);
	DrawPers(CL);

	//CreateThread(0, 0, Sender, &ConnectSocket, 0, 0);
	CreateThread(0, 0, rec, &ConnectSocket, 0, 0);
	CreateThread(0, 0, MovementCharacters, &ConnectSocket, 0, 0);
	Check();

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	// shutdown the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		cout << "shutdown failed with error: " << WSAGetLastError() << "\n";
		closesocket(ConnectSocket);
		WSACleanup();
		return 16;
	}
	else {
		cout << "������� ������� ���������� �������� ���������� � ��������.\n";
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Receive until the peer closes the connection


	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	cout << "������� ������� ���������� ���� ������!\n";

	return 0;
}