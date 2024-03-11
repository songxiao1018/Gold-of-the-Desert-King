#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

#define PORT 8080

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Failed to initialize winsock";
        return -1;
    }

    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    const char* message = "Hello from client";
    char buffer[1024] = { 0 };

    // 创建TCP套接字
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cout << "Failed to create socket";
        return -1;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    // 将IPv4地址从点分十进制转换为二进制
    if (InetPton(AF_INET, _T("192.168.43.155"), &(serverAddress.sin_addr)) <= 0) {
        std::cout << "Invalid address/ Address not supported";
        return -1;
    }

    // 连接到服务器
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cout << "Connection failed";
        return -1;
    }

    // 发送数据到服务器
    if (send(clientSocket, message, strlen(message), 0) < 0) {
        std::cout << "Send failed";
        return -1;
    }
    std::cout << "Hello message sent" << std::endl;

    // 从服务器接收数据
    if (recv(clientSocket, buffer, sizeof(buffer), 0) < 0) {
        std::cout << "Receive failed";
        return -1;
    }
    std::cout << buffer << std::endl;

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}