#include<iostream>
using namespace std;
struct prio_sched
{
    char name;
    int BT;
    int AT;
    int Priority;
    int WT;
    int CT;
    int TAT;
    int RT;
};
int main()
{
    int n,i,time;
    prio_sched temp;
    float tot_wt=0,tot_tat=0;
    cout<<"Enter number of processes: "<<endl;
    cin>>n;
    prio_sched process[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter process: "<<endl;
        cin>>process[i].name;
        cout<<"Enter Arrival Time: "<<endl;
        cin>>process[i].AT;
        cout<<"Enter Burst Time: "<<endl;
        cin>>process[i].BT;
        process[i].RT=process[i].BT;
        cout<<"Enter Priority: "<<endl;
        cin>>process[i].Priority;
    }
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(process[j].AT>=process[j+1].AT && process[j].Priority>process[j+1].Priority)
            {
                temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
    }
    time=0;
    for(i=0;i<n;i++)
    {
        time+=process[i].BT;
        process[i].CT=time;
        process[i].TAT=process[i].CT-process[i].AT;
        process[i].WT=process[i].TAT-process[i].BT;
    }
    cout<<"Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++)
    {
        cout<<process[i].name<<'\t'<<process[i].AT<<'\t'<<process[i].BT<<'\t'<<process[i].Priority<<"\t\t"<<process[i].CT<<'\t'<<process[i].TAT<<'\t'<<process[i].WT<<'\n';
        tot_tat+=process[i].TAT;
        tot_wt+=process[i].WT;
    }
    cout<<"AVERAGE WAITING TIME: "<<tot_wt/n<<endl;
    cout<<"AVERAGE TURNAROUND TIME: "<<tot_tat/n<<endl;
}
