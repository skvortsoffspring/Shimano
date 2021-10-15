#include <iostream>
#include <windows.h>
#include <ctime>
#include "error.h"

#define MAX_MESSAGE 500
#define EXIT "exit"
#define TIME_OUT 180000
#define SECOND 60000
#define  TEST

int main() {

    HANDLE hSlot;
    LPCTSTR slotName = TEXT("\\\\.\\mailslot\\Box");
    char write_buffer[MAX_MESSAGE];                             // buffer to write
    DWORD read_length;                                          // number of bytes sent
    DWORD write_length;                                         // number of bytes required

    clock_t start, stop;                                        // variables for time measurements
    bool first_message = true;

    hSlot = CreateMailslot(
            slotName,
            MAX_MESSAGE,                                        // no maximum message size
            180000,                                             // MAILSLOT_WAIT_FOREVER,              // no time-out for operations
            (LPSECURITY_ATTRIBUTES) nullptr);                   // default security

    std::cout << ">>>>>     Server MS     <<<<<" << std::endl;

    if (hSlot == INVALID_HANDLE_VALUE) {
        GetPipeError(&hSlot);
    }


    while(true)
    {

#ifndef TEST
        cout << "Wait " << TIME_OUT/SECOND << " m ..." << endl;
#endif
        if(ReadFile
                (hSlot,                                 // handle
                 write_buffer,                          // pointer to the buffer
                 (MAX_MESSAGE + 1),  // size buffer
                 &read_length,                         // max number of bytes to be read
                 nullptr                    // pointer to OVERLAPPED structure or null pointer
                ))
        {
            if(first_message) {
                start = clock();
                first_message = false;
            }
#ifndef TEST
            cout << "Received: " << write_buffer << endl;
#endif
            if(!strcmp(write_buffer, EXIT)) {
                stop = clock();
                break;
            }
        }
        else
        {
            GetPipeError(&hSlot);
        }

    }

    cout << "time: " << ((stop - start)) << endl;

    CloseHandle(hSlot);
    return 0;
}
