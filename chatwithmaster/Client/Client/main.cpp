#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

SOCKADDR_IN addr;
SOCKET sConnect;

struct Buffer
{
	int ID;
	char Message[256];
};

// The server has a thread = the client has a thread also
// In this thread the client will handle incoming messages from the server
int ClientThread()
{
	Buffer sbuffer;
	char buffer[sizeof(sbuffer)] = {0};
	ZeroMemory(buffer, 256);
	for(;;Sleep(10))
	{
		if(recv(sConnect, buffer, 256, NULL))
		{
			//cout << buffer << endl;
			memcpy(&sbuffer, buffer,sizeof(buffer));
			cout << "<Client " << sbuffer.ID << ":> " << sbuffer.Message << endl;
		}
		ZeroMemory(buffer, 256);
	}
	return 0;
}

// connect to server and send msgs
int main()
{
	system("cls");

	int RetVal = 0;

	WSAData wsaData;
	WORD DLLVERSION = MAKEWORD(2,1);
	RetVal = WSAStartup(DLLVERSION, &wsaData);
	if(RetVal != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	addr.sin_addr.s_addr = inet_addr("192.168.174.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(444);

	cout << "Connect to Masterserver? [ENTER]" << endl;

	getchar();

	RetVal = connect(sConnect, (SOCKADDR*)&addr,sizeof(addr));

	if(RetVal != 0)
	{
		MessageBoxA(NULL, "Could not connect to server", "Error", MB_OK | MB_ICONERROR);
		main();
	}
	else
	{
		// At first we have to receive the ID
		int ID;
		char* cID = new char[64];
		ZeroMemory(cID, 64);

		recv(sConnect, cID, 64, NULL);
		ID = atoi(cID);

		cout << "Connected" << endl;
		cout << "You are Client No: " << ID << endl;

		

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) ClientThread, NULL, NULL, NULL);
		for(;;Sleep(10))
		{
			Buffer sbuffer;
			/*
			char* buffer = new char[256];
			ZeroMemory(buffer, 256);
			cin >> buffer;
			getchar();
			send(sConnect, buffer, 256, NULL);
			*/

			//ZeroMemory(sbuffer.Message,sizeof(sbuffer.Message));
			cin >> sbuffer.Message;
			sbuffer.ID = ID;
			char* Send = new char[sizeof(sbuffer)];
			memcpy(Send,&sbuffer,sizeof(Buffer));
			send(sConnect, Send, sizeof(sbuffer),NULL);
		}
	}


	return 0;
}