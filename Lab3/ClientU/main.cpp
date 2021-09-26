#pragma comment(lib, "WS2_32.lib")
#include <string>
#include <iostream>
#include "Winsock2.h"
#include "Error.h"
#include <cstdlib>

#define COUNT 10000
#define LOCALHOST                       // закомментировать для использования адреса (не петли)
#define LOCAL_ADDRESS "192.168.0.100"   // адрес компьютера в локальной сети
#define MAX_MESSAGE 50
#define PORT 2000
#define EXIT                            // раскомментировать для выключения сервера
#define PACKET_LOSS                       // тест потери пакетов


using namespace std;

int main()
{
    WSADATA wsaData;

    SOCKET cS;

    SOCKADDR_IN clnt;
    memset(&clnt,0,sizeof(clnt));   // обнулить память

    clnt.sin_family = AF_INET;
    clnt.sin_port = htons(PORT);

#ifdef LOCALHOST
    clnt.sin_addr.s_addr = inet_addr("127.0.0.1");
#endif

#ifndef LOCALHOST
    serv.sin_addr.s_addr = inet_addr(LOCAL_ADDRESS);
#endif

    int lc = sizeof(clnt);
    char ibuf[50];                              //буфер ввода
    int  lb = 0;                                //количество принятых байт
    char obuf[50];                              //буфер вывода
    int  lobuf = 0;                             //количество принятых байт
    char buffer[20];                            //для функции itoa

    try
    {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
            throw SetErrorMsgText("Startup: ", WSAGetLastError());

        if ((cS = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
            throw SetErrorMsgText("socket: ", WSAGetLastError());

        cout << "Will " <<  COUNT <<  "send packages" << endl;

        for (int i = 1; i <= COUNT; i++)
        {

            strcpy(obuf, "Hello from ClientU ");
            strcat(obuf, itoa(i, buffer,10));


            lobuf = sendto(cS, (char *)obuf, MAX_MESSAGE, 0, (sockaddr *) &clnt, lc);
            if (lobuf == SOCKET_ERROR)
                throw SetErrorMsgText("send:", WSAGetLastError());
#ifndef  PACKET_LOSS
            lb = recvfrom(cS, ibuf, MAX_MESSAGE, 0, (sockaddr *) &clnt, &lc);
            if (lb == SOCKET_ERROR)
                throw  SetErrorMsgText("recv:",WSAGetLastError());

            cout << ibuf << endl;
#endif
        }



#ifdef EXIT
        strcpy(obuf, "");
        lobuf = sendto(cS, (char *)obuf, MAX_MESSAGE, 0, (sockaddr *) &clnt, lc);
        if (lobuf == SOCKET_ERROR)
            throw SetErrorMsgText("send:", WSAGetLastError());
#endif

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