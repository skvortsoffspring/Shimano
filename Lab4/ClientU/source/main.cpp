#pragma comment(lib, "WS2_32.lib")
#include <string>
#include <iostream>
#include "Winsock2.h"
#include "../headers/Error.h"
#include "../headers/service.h"

#define BROADCAST                       // закомментировать для использования адреса (не петли)
#define LOCAL_ADDRESS "192.168.0.100"   // адрес компьютера в локальной сети
#define MESSAGE "hello"                 //close для закрытия, hello успешно, остальное игнорируется
#define PORT 2000

using namespace std;

int main()
{
    WSADATA wsaData;
    SOCKET cS;
    SOCKADDR_IN clnt;

    memset(&clnt,0,sizeof(clnt));   // обнулить память

    clnt.sin_family = AF_INET;
    clnt.sin_port = htons(PORT);

#ifdef BROADCAST
    clnt.sin_addr.s_addr = INADDR_BROADCAST;
#endif

#ifndef BROADCAST
    serv.sin_addr.s_addr = inet_addr(LOCAL_ADDRESS);
#endif

    int lc = sizeof(clnt);
    char buffer[50];             //буфер
    bool succes;                 //результат функции GetServer

    try
    {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
            throw SetErrorMsgText("Startup: ", WSAGetLastError());

        if ((cS = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
            throw SetErrorMsgText("socket: ", WSAGetLastError());

        int optval = 1;
        if (setsockopt(cS, SOL_SOCKET, SO_BROADCAST, (char*)&optval, sizeof(int)) == SOCKET_ERROR)
            throw SetErrorMsgText("opt: ", WSAGetLastError());

        strcpy(buffer, MESSAGE);

        succes = GetServer(&cS, buffer, PORT, &clnt, &lc);

        if (closesocket(cS) == SOCKET_ERROR)
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