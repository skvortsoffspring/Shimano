#include <windows.h>
#include <conio.h>
#include "error.h"
#include <iostream>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    HANDLE hPipe;                                       // handle Pipe
    char write_buffer[BUFFER_SIZE];                     // buffer to write
    char read_buffer[BUFFER_SIZE];                      // buffer to read
    DWORD read_length = strlen(read_buffer);            // number of bytes sent

    char   pipeName[256] = "\\\\.\\pipe\\ConsolePipe";   // name pipe

    if(argc > 1)                                        // server name parameter
        sprintf(pipeName, "\\\\%s\\pipe\\ConsolePipe", argv[1]);

    std::cout << "TransactNamedPipe " << std::endl << std::endl;

    std::cout << "I'm wait when server create pipe: " << pipeName << std::endl;
    while(WaitNamedPipe(pipeName, NMPWAIT_WAIT_FOREVER) == false);
    std::cout << "Done, I try connect to server: " << pipeName << std::endl;
    Sleep(200);

    hPipe = CreateFile
            (
                    pipeName,                            // name of pipe
                    GENERIC_READ | GENERIC_WRITE,        // mode access
                    PIPE_READMODE_MESSAGE,               // mode using the file
                    nullptr,                             // security handle
                    OPEN_EXISTING,                       // create mode
                    0,                                   // attributes of file
                    nullptr                              // identifier attributes
            );


    if(hPipe == INVALID_HANDLE_VALUE)
    {
        GetPipeError(&hPipe);
    }

    /*DWORD dwMode = PIPE_WAIT;

    bool fSuccess = SetNamedPipeHandleState(
            hPipe,                                      // identifier pipe
            &dwMode,                                    // new mode pipe
            nullptr,                                    // maximum package bytes
            nullptr);                                   // maximum timeout after sent

    if (!fSuccess)
    {
        printf("SetNamedPipeHandleState failed.\n");
        return 0;
    }
*//*DWORD dwMode = PIPE_WAIT;

    bool fSuccess = SetNamedPipeHandleState(
            hPipe,                                      // identifier pipe
            &dwMode,                                    // new mode pipe
            nullptr,                   // maximum package bytes
            nullptr);                   // maximum timeout after sent

    if (!fSuccess)
    {
        printf("SetNamedPipeHandleState failed.\n");
        return 0;
    }
*/
    while(true)
    {
        puts("Enter message: ");
        gets(write_buffer);
        memset(&read_buffer, 0, BUFFER_SIZE);           // clean buffer to read

        if (TransactNamedPipe(hPipe, write_buffer, strlen(write_buffer) + 1, read_buffer, BUFFER_SIZE, &read_length, nullptr))
           cout << read_buffer << endl;
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