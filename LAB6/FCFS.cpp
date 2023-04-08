#include<iostream>
using namespace std;
struct fcfs
{
    char name;
    int BT;
    int AT;
    int WT;
    int TAT;
    int CT;
};
int main()
{
    int n,time,i;
    float tot_wt=0,tot_tat=0;
    fcfs temp;
    cout<<"Enter number of processes: "<<endl;
    cin>>n;
    fcfs process[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter process: "<<endl;
        cin>>process[i].name;
        cout<<"Enter Burst Time: "<<endl;
        cin>>process[i].BT;
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
    time=process[0].AT+process[0].BT;
    process[0].CT=time;
    i=1;
    while(i<n)
    {
        if(time<process[i].AT)
        {
            time=time+(process[i].AT-time);
        }
        time+=process[i].BT;
        process[i].CT=time;
        i++;
    }
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++)
    {
        process[i].TAT=process[i].CT-process[i].AT;
        process[i].WT=process[i].TAT-process[i].BT;
        cout<<process[i].name<<'\t'<<process[i].AT<<'\t'<<process[i].BT<<'\t'<<process[i].CT<<'\t'<<process[i].TAT<<'\t'<<process[i].WT<<'\n';
        tot_tat+=process[i].TAT;
        tot_wt+=process[i].WT;
    }
    cout<<"AVERAGE WAITING TIME: "<<tot_wt/n<<endl;
    cout<<"AVERAGE TURNAROUND TIME: "<<tot_tat/n<<endl;
}
