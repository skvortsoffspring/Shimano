#include <windows.h>
#include "error.h"
#include <iostream>
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    HANDLE hPipe;
    char write_buffer[BUFFER_SIZE] = "Hello";
    char read_buffer[BUFFER_SIZE];
    char temp[BUFFER_SIZE + 1];
    DWORD read_length = strlen(read_buffer);


    LPSTR pipeName = "\\\\.\\pipe\\ConsolePipe";

    if(argc > 1)
        sprintf(pipeName, "\\\\%s\\pipe\\ConsolePipe", argv[1]);

    std::cout << "CallNamedPipe " << std::endl << std::endl;

    std::cout << "I'm wait when server create pipe: " << pipeName << std::endl;
    while(WaitNamedPipe(pipeName, NMPWAIT_WAIT_FOREVER) == false);
    std::cout << "Done, I try connect to server: " << pipeName << std::endl;

    puts("Enter message: ");
    gets(write_buffer);

    if (CallNamedPipe( pipeName,
                       temp,
                       sizeof (temp),
                       read_buffer,
                       BUFFER_SIZE,
                       &read_length,
                       10000))
        std::cout << read_buffer <<  std::endl;
    else
    {
        GetPipeError(&hPipe);
    }

    return 0;
}