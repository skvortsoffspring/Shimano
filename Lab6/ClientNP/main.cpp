#include <windows.h>
#include <conio.h>
#include "error.h"
#include <iostream>

#define MAX_MESSAGE 512

int main(int argc, char *argv[])
{
    HANDLE hPipe;                                   // handle Pipe
    char write_buffer[MAX_MESSAGE];                 // buffer to write
    DWORD read_length;                              // buffer to read
    DWORD write_length;                             // number of bytes sent

    char   pipeName[256] = "\\\\.\\pipe\\ConsolePipe";

    if(argc > 1)                                        // название сервера через cmd
        sprintf(pipeName, "\\\\%s\\pipe\\ConsolePipe", argv[1]);

    std::cout << "Write/Read " << std::endl << std::endl;
    std::cout << "Write/Read " << std::endl << std::endl;

    std::cout << "I'm wait when server create pipe: " << pipeName << std::endl;

    while(WaitNamedPipe(pipeName, NMPWAIT_WAIT_FOREVER) == false);

    std::cout << "Done, I try connect to server: " << pipeName << std::endl;
    Sleep(200);

    hPipe = CreateFile
            (
                    pipeName,                                   // name of pipe
                    GENERIC_READ | GENERIC_WRITE,               // mode access
                    0,                                          // mode using the file
                    nullptr,                                    // security handle
                    OPEN_EXISTING,                              // create mode
                    0,                                          // attributes of file
                    nullptr                                     // identifier attributes
            );


    if(hPipe == INVALID_HANDLE_VALUE)
    {
        GetPipeError(&hPipe);
    }

    cout << "Connected ... " << endl;

    while(true)
    {
        puts("Enter message: ");
        gets(write_buffer);

        if(!WriteFile(hPipe, write_buffer, strlen(write_buffer) + 1,
                      &write_length, NULL))
            break;

        if(ReadFile(hPipe, write_buffer, 512, &read_length, NULL)) {
            cout << "Received: " <<  write_buffer << endl;
        }
        else
        {
            GetPipeError(&hPipe);
        }

        if(!strcmp(write_buffer, "exit"))
            break;
    }

    CloseHandle(hPipe);
    return 0;
}