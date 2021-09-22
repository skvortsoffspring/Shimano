#include <iostream>
#include "Winsock2.h"
#include "../headers/Error.h"

#define MAX_MESSAGE 50

bool  GetServer(SOCKET *sock,char* call, short port,SOCKADDR_IN * servaddr, int* flen){
    int  lenghtbuffer = 0;                                //количество принятых байт
    char buffer[MAX_MESSAGE];

    lenghtbuffer = sendto(*sock, (char *)call, MAX_MESSAGE, 0, (sockaddr *) servaddr, *flen);
    if (lenghtbuffer == SOCKET_ERROR)
        throw SetErrorMsgText("send:", WSAGetLastError());

    lenghtbuffer = recvfrom(*sock, buffer, MAX_MESSAGE, 0, (sockaddr *) servaddr, flen);
    if (lenghtbuffer == SOCKET_ERROR)
        throw  SetErrorMsgText("recv:",WSAGetLastError());

    std::cout << buffer << std::endl;

}
