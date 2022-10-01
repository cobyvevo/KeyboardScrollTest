// KeyboardInputTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <winuser.h>
#include <hidusage.h>

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    BOOL fEatInput = true;

    if (nCode == HC_ACTION)
    {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
        std::cout << "LPARAM : " << lParam << std::endl;
        std::cout << "WPARAM : " << wParam << std::endl;
        std::cout << "---" << std::endl;
        std::cout << "key : " << p->vkCode << std::endl;
        std::cout << "scancode : " << p->scanCode << std::endl;
        std::cout << "flags : " << p->flags << std::endl;
        std::cout << "extra : " << p->dwExtraInfo << std::endl;
        std::cout << std::endl;
        std::cout << "END OF EVENT-----------------" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return(fEatInput? 1 : CallNextHookEx(NULL, nCode, wParam, lParam));
}

int main()
{
    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);
  
    MSG msg;
    while (!GetMessage(&msg, NULL, NULL, NULL)) {    //this while loop keeps the hook
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hhkLowLevelKybd);

    return 0;
}
