#include<iostream>
using namespace std;
struct sjf
{
    char name;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
    int RT;
};
int srtf(sjf *process,int n,int time)
{
    int mintime=12345;
    int minpos=-1;
    for(int i=0;i<n;i++)
    {
        if(process[i].AT<=time && process[i].RT>0 && process[i].BT<mintime)
        {
            mintime=process[i].BT;
            minpos=i;
        }
    }
    return minpos;
}
int main()
{
    int n,i,time,count=0;
    sjf temp;
    float tot_wt=0,tot_tat=0;
    cout<<"Enter number of processes: "<<endl;
    cin>>n;
    sjf process[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter process: "<<endl;
        cin>>process[i].name;
        cout<<"Enter Arrival time: "<<endl;
        cin>>process[i].AT;
        cout<<"Enter Burst time: "<<endl;
        cin>>process[i].BT;
        process[i].RT=process[i].BT;
    }
    time=0;
    int j,t,rem;
    while(count!=n)
    {
        i=srtf(process,n,time);
        j=i;
        rem=process[i].RT;
        while(j==i)
        {
            time++;
            process[i].RT--;
            j=srtf(process,n,time);
        }
        if(process[i].RT==0)
        {
            count++;
            process[i].CT=time;
            process[i].TAT=process[i].CT-process[i].AT;
            process[i].WT=process[i].TAT-process[i].BT;
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
