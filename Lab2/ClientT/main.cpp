#pragma comment(lib, "WS2_32.lib")
#include <string>
#include <iostream>
#include "Winsock2.h"
#include "Error.h"
#include <ctime>

#define COUNT 1000
#define LOCALHOST
//#define EXIT

using namespace std;

int main()
{
    WSADATA wsaData;

    SOCKET cC;

    SOCKADDR_IN serv;

    serv.sin_family = AF_INET;
    serv.sin_port = htons(2000);

#ifdef LOCALHOST
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
#endif

#ifndef LOCALHOST
    serv.sin_addr.s_addr = inet_addr("192.168.0.100");
#endif
    char ibuf[50];
    int libuf = 0;
    int lobuf = 0;

    clock_t start, stop;
    try
    {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
            throw SetErrorMsgText("Startup: ", WSAGetLastError());

        if ((cC = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
            throw SetErrorMsgText("socket: ", WSAGetLastError());

        if ((connect(cC, (sockaddr*)&serv, sizeof(serv))) == SOCKET_ERROR)
            throw SetErrorMsgText("connect: ", WSAGetLastError());

        for (int i = 1; i <= COUNT; i++)
        {
            string obuf = "Hello from Client " + to_string(i);
            if ((lobuf = send(cC, obuf.c_str(), strlen(obuf.c_str()) + 1, 0)) == SOCKET_ERROR)
                throw SetErrorMsgText("send: ", WSAGetLastError());
            if ((libuf = recv(cC, ibuf, sizeof(ibuf), 0)) == SOCKET_ERROR)
                throw SetErrorMsgText("recv: ", WSAGetLastError());
            cout << ibuf << endl;
        }
        string str = "";
        if ((lobuf = send(cC, str.c_str(), 1, 0)) == SOCKET_ERROR)
            throw SetErrorMsgText("send: ", WSAGetLastError());
        if ((libuf = recv(cC, ibuf, sizeof(ibuf), 0)) == SOCKET_ERROR)
            throw SetErrorMsgText("recv: ", WSAGetLastError());

#ifdef EXIT
        string obuf2;           // = "exit";
        cout << "enter \"exit\" for close server\n>> ";
        cin >> obuf2;
        if ((lobuf = send(cC, obuf2.c_str(), strlen(obuf2.c_str()) + 1, 0)) == SOCKET_ERROR)
            throw SetErrorMsgText("send: ", WSAGetLastError());
#endif

        if (closesocket(cC) == SOCKET_ERROR)
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