#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
using namespace std;
int main()
{
    int n,status;
    pid_t pid;
    char temp[20];
    cout<<"Enter number of strings: "<<endl;
    cin>>n;
    char input[n][20];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter String "<<i+1<<" :"<<endl;
        cin>>input[i];
    }
    pid=fork();
    if(pid==0)
    {
       cout<<"INSIDE CHILD PROCESS"<<endl;
       for(int i=0;i<n-1;i++)
       {
           for(int j=0;j<n-i-1;j++)
           {
               if(strcmp(input[j],input[j+1])>0)
               {
                   strcpy(temp,input[j]);
                   strcpy(input[j],input[j+1]);
                   strcpy(input[j+1],temp);
               }
           }
       }
       cout<<"Sorted strings: "<<endl;
       for(int i=0;i<n;i++)
       {
           cout<<input[i]<<endl;
       }
    }
    else if(pid>0)
    {
        wait(&status);
        if(WIFEXITED(status))
            cout<<"EXITING CHILD PROCESS"<<endl;
        cout<<"INSIDE PARENT PROCESS"<<endl;
        cout<<"Unsorted strings: "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<input[i]<<endl;
        }
        cout<<"EXITING PARENT PROCESS"<<endl;
    }
    else
    {
        cout<<"ERROR!"<<endl;
    }
}
