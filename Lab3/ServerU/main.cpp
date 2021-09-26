#include <string>
#include <iostream>
#include "Winsock2.h"
#pragma comment(lib, "WS2_32.lib")
#include "Error.h"
#include <ctime>

#define PORT 2000
#define MAX_MESSAGE 50
#define PACKET_LOSS                                     // тест потери пакетов

using namespace std;

int main()
{
    WSADATA wsaData;
    SOCKET sock_server;                                  //серверный сокет

    clock_t start, stop;                                 //переменные для оценки времени

    SOCKADDR_IN serv_addr;                               //параметры сервера
    SOCKADDR_IN client_addr;                             //параметры сервера
    memset(&serv_addr, 0, sizeof(serv_addr));       //обнулить память структуры сервер
    memset(&client_addr, 0, sizeof(client_addr));   //обнулить память структуры клиента
    serv_addr.sin_family = AF_INET;                      //тип сетевого адреса
    serv_addr.sin_port = htons(PORT);                    //порт 2000
    serv_addr.sin_addr.s_addr = INADDR_ANY;              //любой адрес для привязки (можно использовать INADDR_LOOPBACK (127.0.0.1)

    int size_sock_addr_client = sizeof(client_addr);
    char buffer[MAX_MESSAGE];                            //буфер ввода
    int  length_buffer = 0;                              //количество принятых байт

    try
    {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) // инициализация библиотеки (MAKEWORD информация о версии, т.е используем сокет 2.0)
            throw SetErrorMsgText("startup: ", WSAGetLastError());

        if ((sock_server = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)    // создаем сокет (AF_INET для протокола ipv4, SOCK_STREAM - TCP, null - для протокола транспортного уровня)
            throw SetErrorMsgText("socket: ", WSAGetLastError());

        if (bind(sock_server, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)      // связываем сокет и данные структуры SOCKADDR_IN
            throw SetErrorMsgText("bind: ", WSAGetLastError());
        cout << "Server UDP " << "port: " << PORT << " address: " << inet_ntoa(serv_addr.sin_addr) << endl;
        do
        {
            //start = clock();

            length_buffer = recvfrom(sock_server, buffer, MAX_MESSAGE, 0, (sockaddr *) &client_addr, &size_sock_addr_client);
            if (length_buffer == SOCKET_ERROR)
                throw  SetErrorMsgText("recv:",WSAGetLastError());
            cout << "!";
            cout << "client (ip: " << inet_ntoa(client_addr.sin_addr) <<
                 ", port: " << client_addr.sin_port << "), message: " << buffer << endl;

#ifndef PACKET_LOSS
            length_buffer = sendto(sock_server, (char *)buffer, MAX_MESSAGE, 0, (sockaddr *) &client_addr, size_sock_addr_client);
            if (length_buffer == SOCKET_ERROR)
                throw SetErrorMsgText("send:", WSAGetLastError());


            cout << "time: " << ((stop - start)) << endl;
#endif
            stop = clock();
            if(strcmp(buffer, "") == 0)                    // условие выхода
                break;
        } while (true);
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