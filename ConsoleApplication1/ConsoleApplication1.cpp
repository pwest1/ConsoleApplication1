// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

DWORD WINAPI threadHelper(LPVOID param)
{
    char * token = (char*)param;
    system(token);

    return 0;
}
void myShell()
{
    cout << "Welcome to myShell" << endl;
    while (1)
    {
        string input;
        cout << "Please enter a command: ";

        std::getline(cin, input);
        //cin >> input;
        //if()
        char * c = new char[input.size() + 1];
        strcpy(c, input.c_str());
        char* token = strtok(c, " ");
        system(token);
        //while (token != nullptr)
        //{
        //    system(c);
        //    token = strtok(nullptr, " ");
        //}
        //

    }
}

int main()
{
    myShell();
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
