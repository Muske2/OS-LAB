#include<iostream>
using namespace std;
struct rr
{
    char name;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
    int RT;
};
int main()
{
    int n,time_quantum,i,time,count=0;
    rr temp;
    float tot_tat=0,tot_wt=0;
    cout<<"Enter number of processes: "<<endl;
    cin>>n;
    rr process[n];
    cout<<"Enter time quantum: "<<endl;
    cin>>time_quantum;
    for(i=0;i<n;i++)
    {
        cout<<"Enter process: "<<endl;
        cin>>process[i].name;
        cout<<"Enter Burst Time: "<<endl;
        cin>>process[i].BT;
        process[i].RT=process[i].BT;
        cout<<"Enter Arrival Time: "<<endl;
        cin>>process[i].AT;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(process[j].AT>process[j+1].AT)
            {
                temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
    }
    i=0;
    time=0;
    while(count!=n)
    {
        if(process[i].RT>0)
        {
         if(process[i].RT>time_quantum)
        {
            process[i].RT-=time_quantum;
            time+=time_quantum;
        }
        else
        {
            time+=process[i].RT;
            process[i].CT=time;
            process[i].TAT=process[i].CT-process[i].AT;
            process[i].WT=process[i].TAT-process[i].BT;
            process[i].RT=0;
            count++;
        }
        }
        if(time<process[i+1].AT && i<n-1)
        {
            continue;
        }
        i++;
        if(i==n)
        {
            i=0;
        }
    }
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++)
    {
        cout<<process[i].name<<'\t'<<process[i].AT<<'\t'<<process[i].BT<<'\t'<<process[i].CT<<'\t'<<process[i].TAT<<'\t'<<process[i].WT<<'\n';
        tot_tat+=process[i].TAT;
        tot_wt+=process[i].WT;
    }
    cout<<"AVERAGE WAITING TIME: "<<tot_wt/n<<endl;
    cout<<"AVERAGE TURNAROUND TIME: "<<tot_tat/n<<endl;
}
