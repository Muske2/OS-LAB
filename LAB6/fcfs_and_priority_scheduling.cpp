#include<iostream>
#include<thread>
#include<stdlib.h>
using namespace std;
int n;
struct process
{
    char name;
    int BT;
    int AT;
    int CT;
    int WT;
    int TAT;
    int Priority;
};
void fcfs(process *p)
{
    float tot_wt=0,tot_tat=0;
    process temp;
    int time=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].AT>p[j+1].AT)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    time=p[0].AT+p[0].BT;
    p[0].CT=time;
    int i=1;
    while(i!=n)
    {
        if(time<p[i].AT)
        {
            time+=(p[i].AT-time);
        }
        time+=p[i].BT;
        p[i].CT=time;
        i++;
    }
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    {
        p[i].TAT=p[i].CT-p[i].AT;
        p[i].WT=p[i].TAT-p[i].BT;
        cout<<p[i].name<<'\t'<<p[i].AT<<'\t'<<p[i].BT<<'\t'<<p[i].CT<<'\t'<<p[i].TAT<<'\t'<<p[i].WT<<'\n';
        tot_tat+=p[i].TAT;
        tot_wt+=p[i].WT;
    }
    cout<<"AVERAGE WAITING TIME: "<<tot_wt/n<<endl;
    cout<<"AVERAGE TURNAROUND TIME: "<<tot_tat/n<<endl;
}
void prio(process* p)
{
    float tot_wt=0,tot_tat=0;
    process temp;
    int time=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].AT>=p[j+1].AT && p[j].Priority>p[j+1].Priority)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        time+=p[i].BT;
        p[i].CT=time;
        p[i].TAT=p[i].CT-p[i].AT;
        p[i].WT=p[i].TAT-p[i].BT;
    }
     cout<<"Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    {
        cout<<p[i].name<<'\t'<<p[i].AT<<'\t'<<p[i].BT<<'\t'<<p[i].Priority<<"\t\t"<<p[i].CT<<'\t'<<p[i].TAT<<'\t'<<p[i].WT<<'\n';
        tot_tat+=p[i].TAT;
        tot_wt+=p[i].WT;
    }
    cout<<"AVERAGE WAITING TIME: "<<tot_wt/n<<endl;
    cout<<"AVERAGE TURNAROUND TIME: "<<tot_tat/n<<endl;
}
int main()
{
    int i,time;
    float tot_wt=0,tot_tat=0;
    cout<<"Enter number of processes: "<<endl;
    cin>>n;
    process p[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter process: "<<endl;
        cin>>p[i].name;
        cout<<"Enter Arrival Time: "<<endl;
        cin>>p[i].AT;
        cout<<"Enter Burst Time: "<<endl;
        cin>>p[i].BT;
        cout<<"Enter Priority: "<<endl;
        cin>>p[i].Priority;
    }
    thread A(fcfs,&p[0]);
    A.join();
    thread B(prio,&p[0]);
    B.join();
}
