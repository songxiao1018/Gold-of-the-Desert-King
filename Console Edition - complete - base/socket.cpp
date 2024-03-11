#include <iostream>
#include <WinSock2.h>

void sendData(const char* data)
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cerr << "Failed to initialize winsock" << std::endl;
		return;
	}

	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		std::cerr << "Failed to create socket" << std::endl;
		return;
	}

	SOCKADDR_IN serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8888);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sendto(clientSocket, data, strlen(data), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

	closesocket(clientSocket);
	WSACleanup();
}

int main()
{
	// 客户端1发送数据
	sendData("Hello from 客户端1");

	// 客户端2发送数据
	sendData("Hello from 客户端2");

	return 0;
}