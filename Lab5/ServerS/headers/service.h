#pragma once

void init
        (       SOCKET*,                    //сокет
                WSADATA*,                   //структура для инициализации lib, "WS2_32.lib"
                SOCKADDR_IN*,int*           //
        );

void initaddr
        (
                SOCKADDR_IN *servaddr,      //socket
                int port,                   //port
                unsigned short address,     //address
                int typeprotocol            //тип протокола 4/6
        );

void destroy
        (
                SOCKET *sock                 //socket
        );