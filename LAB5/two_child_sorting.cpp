#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
using namespace std;
int main()
{
    pid_t pid_1,pid_2;
    int n;
    cout<<"Enter number of strings: "<<endl;
    cin>>n;
    char input[n][20],temp[20];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter string "<<i+1<<" :"<<endl;
        cin>>input[i];
    }
    pid_1=fork();
    if(pid_1==0)
    {
        cout<<"USING BUBBLE SORT"<<endl;
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
       cout<<"Sorted strings(child 1): "<<endl;
       for(int i=0;i<n;i++)
       {
           cout<<input[i]<<endl;
       }
    }
    else if(pid_1>0)
    {
        pid_2=fork();
        if(pid_2==0)
        {
            cout<<"USING SELECTION SORT"<<endl;
            int s;
            for(int i=0;i<n-1;i++)
            {
                s=i;
                strcpy(temp,input[i]);
                for(int j=i+1;j<n;j++)
                {
                    if(strcmp(temp,input[j])>0)
                    {
                        strcpy(temp,input[j]);
                        s=j;
                    }
                }
                strcpy(input[s],input[i]);
                strcpy(input[i],temp);
            }
            cout<<"Sorted strings(child 2): "<<endl;
       for(int i=0;i<n;i++)
       {
           cout<<input[i]<<endl;
       }
        }
        else if(pid_2>0)
    {
        wait(NULL);//not interested to know the status of child process
        cout<<"\nUnsorted strings(parent): "<<endl;
         for(int i=0;i<n;i++)
       {
           cout<<input[i]<<endl;
       }
    }
    }
    else
    {
        cout<<"Fork failed."<<endl;
    }
}
