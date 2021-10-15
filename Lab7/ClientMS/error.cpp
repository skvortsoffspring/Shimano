#include <string>
#include <iostream>
#include "Winsock2.h"
using namespace std;

void GetPipeError(HANDLE* hPipe)           // generation the error, out message and exit from the program
{
    string message_error;
    DWORD error = GetLastError();

    switch(error)
    {
        case ERROR_SEM_TIMEOUT:
            message_error =  "ServerMS: ERROR_SEM_TIMEOUT";
            break;
        case ERROR_ALREADY_EXISTS :
            message_error =  "ServerMS: ERROR_ALREADY_EXISTS ";
            break;
        case ERROR_FILE_NOT_FOUND :
            message_error =  "ServerMS: ERROR_FILE_NOT_FOUND ";
            break;

        default:
            char buffer[33];
            string temp = ulltoa(error, buffer, 10);
            message_error = "ServerMS: error " + temp;
            break;

    }
    cout << message_error;
    CloseHandle(hPipe);

    exit((int)error);
};
