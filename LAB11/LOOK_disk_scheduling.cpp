#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,request,total_seek_time=0,index,head;
    cout<<"Enter total number of cylinders in disk queue(including the initial cylinder disk head is at): "<<endl;
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
    for(int i=index;i>0;i--)
    {
        int seek;
            seek=disk[i]-disk[i-1];
            cout<<disk[i]<<"--->"<<disk[i-1]<<" Seek Time: "<<seek<<endl;
            total_seek_time+=seek;
    }
     total_seek_time+=abs(disk[index+1]-disk[0]);
      cout<<disk[0]<<"--->"<<disk[index+1]<<" Seek Time: "<<abs(disk[index+1]-disk[0])<<endl;
    for(int i=index+1;i<num-1;i++)
    {
        int seek;
        seek=disk[i+1]-disk[i];
        cout<<disk[i]<<"--->"<<disk[i+1]<<" Seek Time: "<<seek<<endl;
        total_seek_time+=seek;
    }
     cout<<"TOTAL SEEK TIME: "<<total_seek_time<<endl;
    cout<<"AVERAGE SEEK TIME: "<<(float)total_seek_time/(num-1)<<endl;
}
