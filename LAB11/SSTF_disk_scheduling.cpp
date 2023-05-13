#include<iostream>
using namespace std;
//Shortest Seek Time First
int main()
{
    int num,count=1,total_seek_time=0;
    cout<<"Enter number of cylinders in disk queue(including the initial): "<<endl;
    cin>>num;
    int disk[num];
    bool visited[num]={false};
    cout<<"Enter initial cylinder: "<<endl;
    cin>>disk[0];
    cout<<"Enter cylinders in disk queue: "<<endl;
    for(int i=1;i<num;i++)
    {
        cin>>disk[i];
    }
    int curr=disk[0],head=disk[0],prev=0;
    while(count!=num)
    {
        int shortest=99999;
        int index=-1;
        for(int j=1;j<num;j++)
        {
            if(!visited[j])
            {
              curr=abs(disk[j]-head);
            if(curr<shortest)
            {
                shortest=curr;
                index=j;
            }
            }
        }
        int seek=abs(head-disk[index]);
        total_seek_time+=seek;
        cout<<head<<"--->"<<disk[index]<<"Seek Time= "<<seek<<endl;
        head=disk[index];
        visited[index]=true;
        count++;
    }
    cout<<"TOTAL SEEK TIME: "<<total_seek_time<<endl;
    cout<<"AVERAGE SEEK TIME: "<<(float)total_seek_time/num<<endl;
}

