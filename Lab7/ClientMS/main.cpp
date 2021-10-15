#include <iostream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "error.h"
#define MESSAGE "Hello from Maislot - client. "
#define EXIT "exit"
#define COUNT 999

int main(int argc, char *argv[]){
    char SlotName[256] = TEXT("\\\\.\\mailslot\\Box");

    if(argc > 1)                                        // название сервера через cmd
        sprintf(SlotName, "\\\\%s\\pipe\\ConsolePipe", argv[1]);

    HANDLE hSlot;
    BOOL fResult;
    DWORD cbWritten;

    hSlot = CreateFile(
            SlotName,                           // file of the name
            GENERIC_WRITE,                      // GENERIC_READ, GENERIC_WRITE or GENERIC_READ | GENERIC_WRITE
            FILE_SHARE_READ,                    // FILE_SHARE_READ,  FILE_SHARE_WRITE, FILE_SHARE_DELETE,  FILE_SHARE_VALID_FLAGS
            (LPSECURITY_ATTRIBUTES) nullptr,    // attributes security or null
            OPEN_EXISTING,                      // mode: CREATE_ALWAYS, CREATE_NEW, OPEN_ALWAYS, OPEN_EXISTING, TRUNCATE_EXISTING
            FILE_ATTRIBUTE_NORMAL,              // attributes for file and parameters security
            (HANDLE) nullptr);                  // for attributes encrypted file

    if (hSlot == INVALID_HANDLE_VALUE)
    {
        GetPipeError(&hSlot);
    }

    for (int i = 0; i < COUNT; ++i) {
        fResult = WriteFile(hSlot,
                            MESSAGE,
                            strlen(MESSAGE)+1,
                            &cbWritten,
                            (LPOVERLAPPED) nullptr);
        //Sleep(2);

        if (!fResult)
        {
            GetPipeError(&hSlot);
        }
    }

    fResult = WriteFile(hSlot,
                        EXIT,
                        strlen(EXIT)+1,
                        &cbWritten,
                        (LPOVERLAPPED) nullptr);

    if (!fResult)
    {
        GetPipeError(&hSlot);
    }

    CloseHandle(hSlot);
    return 0;
}
