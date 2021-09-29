#include <iostream>
#include "Winsock2.h"
#include "../headers/Error.h"
#define SERVER_NAME "DESKTOP-SN48F5O"
#define MAX_MESSAGE 50


bool  GetServerByName(SOCKET *sock,char* call, short port,SOCKADDR_IN * servaddr, int* flen){
    int  lenghtbuffer = 0;                                //количество принятых байт
    char buffer[MAX_MESSAGE];

    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(port);

    struct hostent *remoteHost;

    if ((remoteHost = gethostbyname(SERVER_NAME)) == NULL)
        throw SetErrorMsgText("Error: server not found.", 0);

    servaddr->sin_addr.s_addr = *(u_long *) remoteHost->h_addr_list[0];
    std::cout << inet_ntoa( servaddr->sin_addr) << std::endl;

    lenghtbuffer = sendto(*sock, (char *)call, MAX_MESSAGE, 0, (sockaddr *) servaddr, *flen);
    if (lenghtbuffer == SOCKET_ERROR)
        throw SetErrorMsgText("send:", WSAGetLastError());

    lenghtbuffer = recvfrom(*sock, buffer, MAX_MESSAGE, 0, (sockaddr *) servaddr, flen);
    if (lenghtbuffer == SOCKET_ERROR)
        throw  SetErrorMsgText("recv:",WSAGetLastError());

    std::cout << buffer << std::endl;

}
