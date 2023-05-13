#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,request,total_seek_time=0,count=1,head,index;
    cout<<"Enter total number of cylinders in disk queue(including the initial): "<<endl;
    cin>>num;
    int disk[num];
    cout<<"Enter the cylinder disk head is initially at: "<<endl;
    cin>>disk[0];
    head=disk[0];
    cout<<"Enter cylinders in disk queue: "<<endl;
    for(int i=1;i<num;i++)
    {
        cin>>disk[i];
    }
    sort(disk,disk+num);
    for(int i=0;i<num;i++)
    {
        if(disk[i]==head)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;i--)
    {
        int seek;
        if(i!=0)
        {
            seek=abs(disk[i]-disk[i-1]);
            cout<<disk[i]<<"--->"<<disk[i-1]<<"  Seek Time: "<<seek<<endl;
        }
        else
        {
            seek=abs(disk[i]-0);
            cout<<disk[i]<<"--->"<<"0  Seek Time: "<<seek<<endl;
        }
         total_seek_time+=seek;
    }
    for(int i=num-1;i>index+1;i--)
    {
        int seek;
        if(i!=num-1)
        {
            seek=abs(disk[i]-disk[i-1]);
            cout<<disk[i]<<"--->"<<disk[i-1]<<" Seek Time: "<<seek<<endl;
        }
        else
        {
            seek=199-disk[i];
            cout<<"199--->"<<disk[i]<<" Seek Time: "<<seek<<endl;
            total_seek_time+=seek;
            seek=abs(disk[i]-disk[i-1]);
            cout<<disk[i]<<"--->"<<disk[i-1]<<" Seek Time: "<<seek<<endl;
        }
         total_seek_time+=seek;
    }
     cout<<"TOTAL SEEK TIME: "<<total_seek_time<<endl;
    cout<<"AVERAGE SEEK TIME: "<<(float)total_seek_time/num<<endl;
}

