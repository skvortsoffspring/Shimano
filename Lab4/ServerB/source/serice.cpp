#include <iostream>
#include "Winsock2.h"
#include "../headers/error.h"
#pragma comment(lib, "WS2_32.lib")

void init
        (
                SOCKET *sS,
                WSADATA *wsadata,
                SOCKADDR_IN *servaddr,
                int *flen
        )
{

    if (WSAStartup(MAKEWORD(2, 0), wsadata) != 0)      // инициализация библиотеки (MAKEWORD информация о версии, т.е используем сокет 2.0)
        throw SetErrorMsgText("startup: ", WSAGetLastError());

    if ((*sS = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)    // создаем сокет (AF_INET для протокола ipv4, SOCK_STREAM - TCP, null - для протокола транспортного уровня)
        throw SetErrorMsgText("socket: ", WSAGetLastError());

    if (bind(*sS, (LPSOCKADDR)servaddr, *flen) == SOCKET_ERROR)  // связываем сокет и данные структуры SOCKADDR_IN
        throw SetErrorMsgText("bind: ", WSAGetLastError());

}

void initaddr
        (
                SOCKADDR_IN *servaddr,
                int port,
                unsigned short address,
                int typeprotocol
        )
{
    servaddr->sin_family = typeprotocol;                    //тип сетевого адреса
    servaddr->sin_port = htons(port);                       //порт 2000
    servaddr->sin_addr.s_addr = address;                    //любой адрес для привязки (можно использовать INADDR_LOOPBACK (127.0.0.1)
}

void destroy
        (
                SOCKET * sock
        )
{
    if (closesocket(*sock) == SOCKET_ERROR)
        throw SetErrorMsgText("closesocket: ", WSAGetLastError());

    if (WSACleanup() == SOCKET_ERROR)
        throw SetErrorMsgText("Cleanup: ", WSAGetLastError());

    std::cout << "Server stopped" << std::endl;
    exit(0);
}
