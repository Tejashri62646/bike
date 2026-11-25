
#include <iostream>
#include <winsock2.h>
using namespace std;

int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET serverSocket;
    sockaddr_in serverAddr, clientAddr;

    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr,
        sizeof(serverAddr));

    cout << "[UDP Server] Listening on port 8081..." << endl;

    char buffer[1024] = {0};

    int clientSize = sizeof(clientAddr);

    recvfrom(serverSocket, buffer, sizeof(buffer), 0,
        (sockaddr*)&clientAddr, &clientSize);

    cout << "[UDP Server] Received: " << buffer << endl;

    string reply = "ACK from UDP Server!";

    sendto(serverSocket, reply.c_str(), reply.length(), 0,
        (sockaddr*)&clientAddr, clientSize);

    cout << "[UDP Server] Reply sent." << endl;

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

    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    string message = "Hello UDP Server!";

    sendto(clientSocket, message.c_str(), message.length(), 0,
        (sockaddr*)&serverAddr, sizeof(serverAddr));

    cout << "[UDP Client] Message sent." << endl;

    char buffer[1024] = {0};

    int serverSize = sizeof(serverAddr);

    recvfrom(clientSocket, buffer, sizeof(buffer), 0,
        (sockaddr*)&serverAddr, &serverSize);

    cout << "[UDP Client] Received: " << buffer << endl;

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}
