#include <string>
#include <iostream>
#include "Winsock2.h"
using namespace std;

void GetPipeError(HANDLE* hPipe)                    // generation the error, out message and exit from the program
{
    string message_error;
    DWORD error = GetLastError();

    switch(error)
    {
        case ERROR_NO_DATA:
            message_error = "ConnectNamedPipe: ERROR_NO_DATA";
            break;

        case ERROR_PIPE_CONNECTED:
            message_error = "ConnectNamedPipe: ERROR_PIPE_CONNECTED";
            break;

        case ERROR_PIPE_LISTENING:
            message_error =  "ConnectNamedPipe: ERROR_PIPE_LISTENING";
            break;

        case ERROR_CALL_NOT_IMPLEMENTED:
            message_error =  "ConnectNamedPipe: ERROR_CALL_NOT_IMPLEMENTED";
            break;

        case ERROR_INVALID_PARAMETER:
            message_error =  "ConnectNamedPipe: ERROR_INVALID_PARAMETER";
            break;

        case ERROR_FILE_NOT_FOUND:
            message_error =  "ConnectNamedPipe: ERROR_FILE_NOT_FOUND";
            break;

        case ERROR_BAD_PIPE:
            message_error =  "ConnectNamedPipe: ERROR_BAD_PIPE";
            break;

        case ERROR_BROKEN_PIPE:
            message_error =  "ConnectNamedPipe: ERROR_BROKEN_PIPE";
            break;

        case ERROR_MORE_DATA:
            message_error =  "ConnectNamedPipe: ERROR_MORE_DATA";
            break;

        default:
            char buffer[33];                                // 33 it's max size buffer ulltoa(...)
            string temp = ulltoa(error, buffer, 10);
            message_error = "ConnectNamedPipe: Error " + temp;
            break;

    }
    cout << message_error;
    CloseHandle(hPipe);

    exit((int)error);
};
