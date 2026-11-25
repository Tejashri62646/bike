
#include <iostream>
#include <winsock2.h>
using namespace std;

int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET serverSocket, clientSocket;
    sockaddr_in serverAddr, clientAddr;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    listen(serverSocket, 5);

    cout << "[TCP Server] Listening on port 9090..." << endl;

    int clientSize = sizeof(clientAddr);
    clientSocket = accept(serverSocket,
        (sockaddr*)&clientAddr, &clientSize);

    cout << "[TCP Server] Client connected." << endl;

    char buffer[1024] = {0};

    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "[TCP Server] Received: " << buffer << endl;

    string reply = "ACK from TCP Server!";

    send(clientSocket, reply.c_str(), reply.length(), 0);

    cout << "[TCP Server] Reply sent." << endl;

    closesocket(clientSocket);
    closesocket(serverSocket);

    WSACleanup();

    return 0;
}



#include <iostream>
#include <winsock2.h>
using namespace std;

int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET clientSocket;
    sockaddr_in serverAddr;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(clientSocket, (sockaddr*)&serverAddr,
        sizeof(serverAddr));

    string message = "Hello TCP Server!";

    send(clientSocket, message.c_str(), message.length(), 0);

    cout << "[TCP Client] Message sent." << endl;

    char buffer[1024] = {0};

    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "[TCP Client] Received: " << buffer << endl;

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}
