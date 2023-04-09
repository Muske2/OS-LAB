#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
pid_t getpid(void);
pid_t getppid(void);
int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        cout<<"This is the child process."<<endl;
        cout<<"Process ID: "<<getpid()<<endl;
        cout<<"Parent Process ID: "<<getppid()<<endl;
    }
    else if(pid>0)
    {
        cout<<"This is the parent process."<<endl;
        cout<<"Process ID: "<<getpid()<<endl;
        cout<<"Parent Process ID: "<<getppid()<<endl;
    }
    else if(pid<0)
    {
        cout<<"Error in forking a child process."<<endl;
    }
}
