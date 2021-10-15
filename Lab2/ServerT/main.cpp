#include <string>
#include <iostream>
#include "Winsock2.h"
#include "Error.h"
#include <ctime>
#pragma comment(lib, "WS2_32.lib")

using namespace std;

int main()
{
    WSADATA wsaData;
    SOCKET sS;                                  //серверный сокет

    clock_t start, stop;                        //переменные для оценки времени

    SOCKADDR_IN serv;                           //параметры сокета sS
    serv.sin_family = AF_INET;                  //тип сетевого адреса
    serv.sin_port = htons(2000);       //порт 2000
    serv.sin_addr.s_addr = INADDR_ANY;          //любой адрес для привязки (можно использовать INADDR_LOOPBACK (127.0.0.1)

    SOCKET cS;                                  //создание канала на стороне сервера и создание сокета для обмена данными по этому каналу
    SOCKADDR_IN clnt;                           //структура для хранения сокета
    memset(&clnt, 0, sizeof(clnt));        //обнуляем память
    int lclnt = sizeof(clnt);                   //размер SOCKADDR_IN

    char ibuf[50];                              //буфер ввода
    int libuf = 0;                              //количество принятых байт
    int lobuf = 0;                              //количество отправленных байт
    bool exit = false;

    try
    {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)      // инициализация библиотеки (MAKEWORD информация о версии, т.е используем сокет 2.0)
            throw SetErrorMsgText("startup: ", WSAGetLastError());

        if ((sS = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)    // создаем сокет (AF_INET для протокола ipv4, SOCK_STREAM - TCP, null - для протокола транспортного уровня)
            throw SetErrorMsgText("socket: ", WSAGetLastError());

        if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)          // связываем сокет и данные структуры SOCKADDR_IN
            throw SetErrorMsgText("bind: ", WSAGetLastError());

        do
        {
            cout << "I listen!" << endl;
            if ((cS = accept(sS, (sockaddr*)&clnt, &lclnt)) == INVALID_SOCKET)      //метод для ожидания подключения клиентов (сокет, структура параметров подключения, размер структуры SOCKADDR_IN)
                throw SetErrorMsgText("accept: ", WSAGetLastError());

            //cout << "adress: " << inet_ntoa(clnt.sin_addr) << ", port: " << clnt.sin_port << endl;

            while (true)
            {
                start = clock();                                                                //начало измерения
                if ((libuf = recv(cS, ibuf, sizeof(ibuf), 0)) == SOCKET_ERROR)               //получение сообщения (сокет клиента, буффер ввода, индикатор особого режима маршрутизатора)
                    throw SetErrorMsgText("recv: ", WSAGetLastError());

                string obuf = ibuf;

                if ((lobuf = send(cS, obuf.c_str(), strlen(obuf.c_str()) + 1, 0)) == SOCKET_ERROR)   //получение сообщения (сокет клиента, буффер выводы, индикатор особого режима маршрутизатора)
                    throw SetErrorMsgText("send: ", WSAGetLastError());

                cout << ibuf << endl;

                if(exit) break;
                if (strcmp(ibuf, "") == 0){
                    exit = true;
                }

                stop = clock();
                cout << "time: " << ((stop - start)) << endl;
            }

            if (strcmp(ibuf, "exit") == 0)
                break;
            exit = false;
        } while (true);

        if (closesocket(sS) == SOCKET_ERROR)
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