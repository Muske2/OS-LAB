#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct sjf
{
    char name;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
};
bool bsort(sjf a,sjf b)
{
    return a.BT<b.BT;
}
bool asort(sjf a,sjf b)
{
    return a.AT<b.AT;
}
int main()
{
    sjf temp;
    int n,time,j,i;
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
    }
    sort(process,process+n,bsort);
    sort(process,process+n,asort);
    time=0;
    for(i=0;i<n;i++)
    {
        j=i;
        while(process[j].AT<=time && j!=n)
        {
            j++;
        }
         sort(process+i,process+j,bsort);
         time+=process[i].BT;
            process[i].CT=time;
            process[i].TAT=process[i].CT-process[i].AT;
        process[i].WT=process[i].TAT-process[i].BT;
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
