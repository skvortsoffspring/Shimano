#include <iostream>
#include "../headers/error.h"
#include "Winsock2.h"
#include "../headers/service.h"
#include "../headers/sendreceive.h"

#define CALL_SIGN "hello"
#define MAX_MESSAGE 50
#define CLOSE "close"
#define PRINT_INFO_CLIENT  cout << "client (ip: " << inet_ntoa(client_addr->sin_addr) <<\
                            ", port: " << client_addr->sin_port << "), message: " << name << endl;
using namespace std;

bool  GetRequestFromClient(SOCKET sS, char *name, short port, SOCKADDR_IN *client_addr, int *flen)
{
    int lengthBuffer = 0;                                //буффер для сообщения
    SOCKADDR_IN temp;
    struct hostent *remoteHost;

    lengthBuffer = recvfrom(sS, name, MAX_MESSAGE, 0, (sockaddr *) &temp, flen);
    if (lengthBuffer == SOCKET_ERROR){
        if(WSAGetLastError() == WSAETIMEDOUT)
            return false;
        else
            throw  SetErrorMsgText("recvfrom: ",WSAGetLastError());
    }

    if(strcmp(name, CALL_SIGN) == 0)
    {
        memset(client_addr,0,sizeof(*client_addr));
        cout << "Confirmed" << endl;
        client_addr->sin_addr = temp.sin_addr;
        client_addr->sin_port = temp.sin_port;
        client_addr->sin_family = temp.sin_family;

        char *ipClient = (char*)&client_addr->sin_addr;
        int length_IP = sizeof(client_addr->sin_addr);

        remoteHost = gethostbyaddr(ipClient, length_IP, AF_INET);
        if(remoteHost == nullptr){
            throw  SetErrorMsgText("ERROR : gethostbyaddr ", -1);
        }

        cout << remoteHost->h_name << endl;

        PRINT_INFO_CLIENT
        return true;
    }
    else if(strcmp(name, CLOSE) == 0)
    {
        PutAnswerToClient(sS, (char*)"Server will stopped", client_addr, flen);
        PRINT_INFO_CLIENT
        destroy(&sS);
    }else {
        cout << "Rejected" << endl;
        PutAnswerToClient(sS, (char*)"", client_addr, flen);
        return false;
    }
}

bool  PutAnswerToClient(SOCKET sock, char* name, SOCKADDR_IN *client_addr, int* lto)
{
    int lengthBuffer = 0;                                //буффер для сообщения

    lengthBuffer = sendto(sock, name, MAX_MESSAGE, 0, (sockaddr *) client_addr, *lto);

    if (lengthBuffer == SOCKET_ERROR)
        return false;
    else
        return true;

}
