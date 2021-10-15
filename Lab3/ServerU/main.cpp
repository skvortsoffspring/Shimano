#include <string>
#include <iostream>
#include "Winsock2.h"
#pragma comment(lib, "WS2_32.lib")
#include "Error.h"
#include <ctime>

#define PORT 2000
#define MAX_MESSAGE 50
#define PACKET_LOSS

using namespace std;

int main()
{
    WSADATA wsaData;
    SOCKET sock_server;

    clock_t start, stop;

    SOCKADDR_IN serv_addr;
    SOCKADDR_IN client_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    int size_sock_addr_client = sizeof(client_addr);
    char buffer[MAX_MESSAGE];
    int  length_buffer = 0;
    int count_received_packs = 0;
    bool first_pause = true;

    try
    {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
            throw SetErrorMsgText("startup: ", WSAGetLastError());

        if ((sock_server = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
            throw SetErrorMsgText("socket: ", WSAGetLastError());

        if (bind(sock_server, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
            throw SetErrorMsgText("bind: ", WSAGetLastError());
        cout << "Server UDP " << "port: " << PORT << " address: " << inet_ntoa(serv_addr.sin_addr) << endl;

        do
        {
            //start = clock();

            length_buffer = recvfrom(sock_server, buffer, MAX_MESSAGE, 0, (sockaddr *) &client_addr, &size_sock_addr_client);
            if (length_buffer == SOCKET_ERROR)
                throw  SetErrorMsgText("recv:",WSAGetLastError());

#ifdef PACKET_LOSS
            if(first_pause) {
                Sleep(3000);
                first_pause = false;
            };
            count_received_packs++;
#endif

#ifndef PACKET_LOSS
            length_buffer = sendto(sock_server, (char *)buffer, MAX_MESSAGE, 0, (sockaddr *) &client_addr, size_sock_addr_client);
            if (length_buffer == SOCKET_ERROR)
                throw SetErrorMsgText("send:", WSAGetLastError());

            cout << "client (ip: " << inet_ntoa(client_addr.sin_addr) <<
                 ", port: " << client_addr.sin_port << "), message: " << buffer << endl;

#endif
            //cout << "time: " << ((stop - start)) << endl;
            //stop = clock();
            if(strcmp(buffer, "") == 0)                    // условие выхода
                break;

        } while (true);
        cout << "RECEIVED: " << count_received_packs << endl;
        if (closesocket(sock_server) == SOCKET_ERROR)
            throw SetErrorMsgText("closesocket: ", WSAGetLastError());

        if (WSACleanup() == SOCKET_ERROR)
            throw SetErrorMsgText("Cleanup: ", WSAGetLastError());
        }

    catch (string errorMsgText)
    {
        cout << endl << errorMsgText << endl;
    }

    return 0;
}