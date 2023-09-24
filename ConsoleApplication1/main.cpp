#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

using namespace std;

char input[75]; 

void * threadHelper(void * param)
{
 
    
    //char [] command = (char[] param);
    system(input);
    
    pthread_exit(0);
    
}
void myShell()
{
    pthread_t tid; //the thread id
    pthread_attr_t attr; //set of thread attr
    
    
    
    cout << "Welcome to myShell" << endl;
    while(1)
    {
        //string input;
        cout << "Please enter a command: ";
        cin.getline(input, 200);
        cout << input;
        
        
       
        char * token = strtok(input, " ");
     
        if(strcmp(token, "dir") == 0 || strcmp(token, "ls") == 0 
        || strcmp(token, "help") == 0 || strcmp(token, "pwd") == 0 || 
        strcmp(token, "ps") == 0 || strcmp(token, "gedit") == 0)
        {
            pthread_attr_init(&attr);
            pthread_create(&tid, &attr, threadHelper, token);
            
        }
        else if(strcmp(token, "echo") == 0 || strcmp(token, "ping") == 0)
        {
            pthread_attr_init(&attr);
            pthread_create(&tid, &attr, threadHelper, token);
        }
        else if(strcmp(token, "exit") == 0 || strcmp(token, "quit") == 0)
        {
            cout << "Thank you!"; 
            break;
        }
        else
        {
            cerr << "Invalid Input. Enter Help for list of supported commands." << endl;
        }
        
    }
}
int main()
{
  
    myShell();
    return 0;
}
