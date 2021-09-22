#pragma once

bool  GetRequestFromClient(     //сообщение от клиента и проверка позывного
        SOCKET           sock,  //сокет сервера
        char*            name,  //[in] позывной сервера
        short            port,  //[in] номер просушиваемого порта
        SOCKADDR_IN*     from,  //[out] указатель на SOCKADDR_IN
        int*             flen   //[out] указатель на размер from
);

bool  PutAnswerToClient(       //ответ клиенту
        SOCKET           sock, //сокет сервера
        char*            name, //[in] позывной сервера
        SOCKADDR_IN*     to,   //[in] указатель на SOCKADDR_IN
        int*             lto   //[in] указатель на размер from
);
