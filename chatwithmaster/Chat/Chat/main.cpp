// MASTER SERVER
// Multithread = able to run on other pc's

#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

using namespace std;

// Winsock Standard stuff
SOCKADDR_IN addr;

SOCKET sListen;
SOCKET sConnect;
SOCKET* Connections;

int addrlen = sizeof(addr);
int ConCounter = 0;

int InitWinSock()
{
	int RetVal = 0;
	WSAData wsaData;
	WORD DLLVERSION = MAKEWORD(2,1);
	RetVal = WSAStartup(DLLVERSION, &wsaData);

	return RetVal;
}

struct Buffer
{
	int ID;
	char Message[256];
};

// SERVER THREAD
// ID specifies the client to which the thread belongs to
int ServerThread(int ID)
{
	Buffer sbuffer;

	char* Recv = new char[256];
	//ZeroMemory(Recv, sizeof(Recv));

	char* Send = new char[sizeof(sbuffer)];
	ZeroMemory(Send, sizeof(Buffer));

	for(;;Sleep(10))
	{
		if(recv(Connections[ID],Recv,256,NULL))
		{
			sbuffer.ID = ID;
			memcpy(sbuffer.Message, Recv, 256);
			memcpy(Send, &sbuffer, sizeof(Buffer));
			// cout << Recv << endl;
			//
			for(int a = 0; a != ConCounter; a++)
			{
				if(Connections[a] == Connections[ID])
				{

				}
				else
				{
					send(Connections[a], Recv, 256, NULL);
				}
			}
			ZeroMemory(Recv,256);
		}
	}
}

int main()
{
	int RetVal = 0;
	RetVal = InitWinSock();
	if(RetVal != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	// In Connections, we can store all (n) clients that connected
	// (n) = 64 (see below)
	Connections = (SOCKET*)calloc(64, sizeof(SOCKET));

	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	addr.sin_addr.s_addr = inet_addr("192.168.174.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(444);

	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	// Listen will listen for maximum of (n) clients
	listen(sListen, 64);

	for(;;Sleep(50))
	{
		if(sConnect = accept(sListen, (SOCKADDR*)&addr, &addrlen))
		{
			// Ok now we have to think about what the server should
			// do if a connection was established
			// first we need a connection counter
			// we save the client-sockets into our socket-array
			Connections[ConCounter] = sConnect;

			// Converting int ConCounter to a char* called ID here:
			char* ID = new char[64];
			ZeroMemory(ID, sizeof(ID));

			itoa(ConCounter, ID, 10);
			send(Connections[ConCounter], ID, sizeof(ID), NULL);

			ConCounter++;

			// Create a thread who listens for incoming messages
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) ServerThread, (LPVOID)(ConCounter - 1), NULL, NULL);
		}
	}

	return RetVal;
}