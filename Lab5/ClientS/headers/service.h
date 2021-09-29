//
// Created by Skvortsoff on 9/19/2021.
//

bool  GetServerByName(
        SOCKET*          sock,
        char*            call, //[in] позывной сервера
        short            port, //[in] номер порта сервера
        SOCKADDR_IN*     from, //[out] указатель на SOCKADDR_IN
        int*             flen  //[out] указатель на размер from
);
