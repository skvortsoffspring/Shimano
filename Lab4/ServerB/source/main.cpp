#include <string>
#include <iostream>
#include "Winsock2.h"
#pragma comment(lib, "WS2_32.lib")
#include "../headers/error.h"
#include "../headers/sendreceive.h"
#include "../headers/service.h"

#define PORT 2000
#define MAX_MESSAGE 50

using namespace std;

int main()
{
    WSADATA wsaData;
    SOCKET sock_serv;                                   //серверный сокет
    SOCKADDR_IN serv_addr;                               //параметры сокета sS
    SOCKADDR_IN client_addr;                               //параметры сокета sS
    memset(&serv_addr, 0, sizeof(serv_addr));          // обнулить память

    char ibuf[MAX_MESSAGE];                             //буфер ввода
    int lc = sizeof(serv_addr);                          //размер структуры

    bool iSreceiving;                                   //позывной совпал
    bool iSsending;                                     //успешный ответ клиенту

    try
    {
        initaddr(&serv_addr, PORT, INADDR_ANY, AF_INET);
        init(&sock_serv, &wsaData, &serv_addr, &lc);
        cout << "Listen" << endl;

        while (true){
            iSreceiving = GetRequestFromClient(sock_serv, ibuf, 2000, &client_addr, &lc );

            if(iSreceiving)
                iSsending = PutAnswerToClient(sock_serv, ibuf, &client_addr, &lc);

        }
    }
    catch (string errorMsgText)
    {
        cout << endl << errorMsgText << endl;
    }

    return 0;
}