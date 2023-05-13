#include<iostream>
using namespace std;
int main()
{
    int num,request,total_seek_time=0,curr;
    cout<<"Enter total number of cylinders in disk queue(including the initial cylinder disk head is at): "<<endl;
    cin>>num;
    int disk[num];
    cout<<"Enter the cylinder disk head is initially at: "<<endl;
    cin>>disk[0];
    cout<<"Enter cylinders in disk queue: "<<endl;
    for(int i=1;i<num;i++)
    {
        cin>>disk[i];
    }
    curr=disk[0];
    cout<<"FCFS DISK SCHEDULING"<<endl;
    for(int i=1;i<num;i++)
    {
        cout<<curr<<"--->";
        request=disk[i];
        total_seek_time+=abs(curr-request);
        curr=disk[i];
    }
    cout<<disk[num-1]<<endl;
    cout<<"TOTAL SEEK TIME: "<<total_seek_time<<endl;
    cout<<"AVERAGE SEEK TIME: "<<(float)total_seek_time/num<<endl;
}
