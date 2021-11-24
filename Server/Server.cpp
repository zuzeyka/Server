// https://docs.microsoft.com/en-us/windows/win32/winsock/complete-server-code
// #undef UNICODE

#define WIN32_LEAN_AND_MEAN // To speed the build process: https://stackoverflow.com/questions/11040133/what-does-defining-win32-lean-and-mean-exclude-exactly

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
// #include <winsock2.h>
#include <ws2tcpip.h> // WSADATA type; WSAStartup, WSACleanup functions and many more
using namespace std;

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 256
#define DEFAULT_PORT "27015" // a port is a logical construct that identifies a specific process or a type of network service - https://en.wikipedia.org/wiki/Port_(computer_networking)

#define PAUSE 10

DWORD WINAPI Shower(void* p)
{
    while (true)
    {
        SOCKET temp = *((SOCKET*)p);
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cci;
        cci.bVisible = false;
        cci.dwSize = 100;
        SetConsoleCursorInfo(h, &cci);
        char* message = new char[DEFAULT_BUFLEN];
        COORD pers = { 0, 2 };\
        int iResult = recv(temp, message, DEFAULT_BUFLEN, 0); // The recv function is used to read incoming data: https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv
        message[iResult] = '\0';
        string str = message;
        int number = stoi(str);
        auto it = find_if(str.begin(), str.end(), isdigit);

        if (it != str.end()) number = stod(str.c_str() + (it - str.begin()));
        string st;
        for (int i = 0, b = 0; i < DEFAULT_BUFLEN; i++)
        {
            if (b == 1)
            {
                st += message[i];
            }
            else if (message[i] == ' ')
            {
                b = 1;
            }
            else if (message[i] == '\0')
            {
                break;
            }
        }
        int number2 = stoi(st);
        pers.X = number;
        pers.Y = number2;
        system("cls");
        SetConsoleCursorPosition(h, pers);
        SetConsoleTextAttribute(h, 9);
        cout << (char)1;
    }
}
int main()
{
    setlocale(0, "");
    system("title SERVER SIDE");
    cout << "������� ������� �������!\n";
    Sleep(PAUSE);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Initialize Winsock
    WSADATA wsaData; // The WSADATA structure contains information about the Windows Sockets implementation: https://docs.microsoft.com/en-us/windows/win32/api/winsock/ns-winsock-wsadata
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData); // The WSAStartup function initiates use of the Winsock DLL by a process: https://firststeps.ru/mfc/net/socket/r.php?2
    if (iResult != 0) {
        cout << "WSAStartup failed with error: " << iResult << "\n";
        cout << "����������� Winsock.dll ������ � �������!\n";
        return 1;
    }
    else {
        cout << "����������� Winsock.dll ������ �������!\n";
        Sleep(PAUSE);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct addrinfo hints; // The addrinfo structure is used by the getaddrinfo function to hold host address information: https://docs.microsoft.com/en-us/windows/win32/api/ws2def/ns-ws2def-addrinfoa
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET; // The Internet Protocol version 4 (IPv4) address family
    hints.ai_socktype = SOCK_STREAM; // Provides sequenced, reliable, two-way, connection-based byte streams with a data transmission mechanism
    hints.ai_protocol = IPPROTO_TCP; // The Transmission Control Protocol (TCP). This is a possible value when the ai_family member is AF_INET or AF_INET6 and the ai_socktype member is SOCK_STREAM
    hints.ai_flags = AI_PASSIVE; // The socket address will be used in a call to the "bind" function

    // Resolve the server address and port
    struct addrinfo* result = NULL;
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        cout << "getaddrinfo failed with error: " << iResult << "\n";
        cout << "��������� ������ � ����� ������� ������ c �������!\n";
        WSACleanup(); // The WSACleanup function terminates use of the Winsock 2 DLL (Ws2_32.dll): https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsacleanup
        return 2;
    }
    else {
        cout << "��������� ������ � ����� ������� ������ �������!\n";
        Sleep(PAUSE);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Create a SOCKET for connecting to server
    SOCKET ListenSocket = INVALID_SOCKET;
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        cout << "socket failed with error: " << WSAGetLastError() << "\n";
        cout << "�������� ������ ������ c �������!\n";
        freeaddrinfo(result);
        WSACleanup();

        return 3;
    }
    else {
        cout << "�������� ������ �� ������� ������ �������!\n";
        Sleep(PAUSE);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen); // The bind function associates a local address with a socket: https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-bind
    if (iResult == SOCKET_ERROR) {
        cout << "bind failed with error: " << WSAGetLastError() << "\n";
        cout << "��������� ������ �� IP-������ ������ � �������!\n";
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 4;
    }
    else {
        cout << "��������� ������ �� IP-������ ������ �������!\n";
        Sleep(PAUSE);
    }

    freeaddrinfo(result);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    iResult = listen(ListenSocket, SOMAXCONN); // The listen function places a socket in a state in which it is listening for an incoming connection: https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-listen
    if (iResult == SOCKET_ERROR) {
        cout << "listen failed with error: " << WSAGetLastError() << "\n";
        cout << "��������� ���������� �� ������� �� ��������. ���-�� ����� �� ���!\n";
        closesocket(ListenSocket);
        WSACleanup();
        return 5;
    }
    else {
        cout << "���������� ��������� ���������� �� �������. ����������, ��������� ���������� ����������! (client.exe)\n";
        // ����� ����� ���� �� ��������� ����� ��������� � ��������� ������
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Accept a client socket
    SOCKET ClientSocket = INVALID_SOCKET;
    ClientSocket = accept(ListenSocket, NULL, NULL); // The accept function permits an incoming connection attempt on a socket: https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept
    if (ClientSocket == INVALID_SOCKET) {
        cout << "accept failed with error: " << WSAGetLastError() << "\n";
        cout << "���������� � ���������� ����������� �� �����������! ������!\n";
        closesocket(ListenSocket);
        WSACleanup();
        return 6;
    }
    else {
        cout << "���������� � ���������� ����������� ����������� �������!\n";
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // No longer need server socket
    closesocket(ListenSocket);
    // Receive until the peer shuts down the connection
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = false;
    cci.dwSize = 100;
    SetConsoleCursorInfo(h, &cci);
    system("cls");
    COORD pers = { 0, 2 };
    SetConsoleCursorPosition(h, pers);
    SetConsoleTextAttribute(h, 9);
    SetConsoleCursorPosition(h, pers);
    cout << " ";
    SetConsoleCursorPosition(h, pers);
    SetConsoleTextAttribute(h, 9);
    cout << (char)1;
    CreateThread(0, 0, Shower, &ClientSocket, 0, 0);
    Sleep(INFINITE);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND); // The shutdown function disables sends or receives on a socket: https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-shutdown
    if (iResult == SOCKET_ERROR) {
        cout << "shutdown failed with error: " << WSAGetLastError() << "\n";
        cout << "���, ������ ���������� (shutdown) ����� ������ ((\n";
        closesocket(ClientSocket);
        WSACleanup();
        return 9;
    }
    else {
        cout << "������� ������� ���������� ���� ������! �� ����� ��������! :)\n";
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}