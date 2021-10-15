#include <windows.h>
#include <iostream>
#include "error.h"
#define MAX_MESSAGE 512

int main() {

    HANDLE hPipe;                                               // handle Pipe
    LPSTR pipeName = TEXT("\\\\.\\pipe\\ConsolePipe");    // name pipe
    char write_buffer[MAX_MESSAGE];                             // buffer to write
    DWORD read_length;                                          // number of bytes sent
    DWORD write_length;                                         // number of bytes required

    std::cout << ">>>>>     ServerNP     <<<<<" << std::endl;

    hPipe = CreateNamedPipe
            (
            pipeName,                               // name pipe
            PIPE_ACCESS_DUPLEX,                     // mode opening
            PIPE_TYPE_MESSAGE | PIPE_WAIT,          // mode work
            1,                                      // numbers channel
            0,                                      // buffer size out
            0,                                      // buffer size in
            INFINITE,                               // time wait
            nullptr                                 // security handle
            );

    if (hPipe == INVALID_HANDLE_VALUE) {
        GetPipeError(&hPipe);
    }

   cout << "Connections wait ... " << endl;

    if(ConnectNamedPipe(hPipe, nullptr) == false)
    {
        GetPipeError(&hPipe);
    }

    cout << "Pipe creation was successful" << endl;

    while(true)
    {

        if(ReadFile(hPipe, write_buffer, MAX_MESSAGE + 1, &read_length, nullptr))
        {
            if(!WriteFile(hPipe, write_buffer, strlen(write_buffer),
                          &write_length, nullptr))
                break;

            cout << "Received: " << write_buffer << endl;

            if(!strcmp(write_buffer, "exit"))
                break;
        }
        else
        {
            GetPipeError(&hPipe);
        }

    }

    CloseHandle(hPipe);
    return 0;
}
