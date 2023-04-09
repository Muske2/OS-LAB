#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int num_proc,num_res;
 int work[20][20];
int allocation[20][20],need[20][20],maximum[20][20];
void safetyalgo(bool safe)
{
    int count,k=0,proc=0;
    bool proc_done[num_proc];
    for(int i=0;i<num_proc;i++)
    {
        proc_done[i]=false;
    }
    cout<<"SAFE SEQUENCE: \n"<<"< ";
     for(int i=0;i<num_proc;i++)
    {
        count=0;
        if(!proc_done[i])
        {
            for(int j=0;j<num_res;j++)
        {
            if(work[k][j]>=need[i][j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if(count==num_res)
        {
            proc_done[i]=true;
            cout<<"PROCESS "<<i+1<<"  , ";
            k++;proc++;
            for(int m=0;m<=num_res;m++)
            {
                work[k][m]=work[k-1][m]+allocation[i][m];
            }
            i=-1;
        }
        }
    }
    if(proc!=num_proc)
    {
        safe=false;
    }
    else
    {
     cout<<">\n";
    safe=true;
    }
    //cout<<"WORK: \n";
    //for(int i=0;i<=num_proc;i++)
    //{
      //  for(int j=0;j<num_res;j++)
        //{
          //  cout<<work[i][j]<<" ";
        //}
        //cout<<endl;
    //}
}
bool requestalgo(vector<int>request,bool safe,int p)
{
    for(int i=0;i<num_res;i++)
    {
        if(request[i]>need[p][i])
        {
            return false;
        }
    }
    for(int i=0;i<num_res;i++)
    {
        work[0][i]-=request[i];
        allocation[p][i]+=request[i];
        need[p][i]=maximum[p][i]-allocation[p][i];
    }
    safetyalgo(safe);
    if(!safe)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int instance;
    vector<int>available,request;
    bool safe=false;
    cout<<"Enter number of processes: "<<endl;
    cin>>num_proc;
    cout<<"Enter number of resources: "<<endl;
    cin>>num_res;
    for(int i=0;i<num_res;i++)
    {
        cout<<"Enter available resource instances of resource "<<i+1<<" :"<<endl;
        cin>>instance;
        available.push_back(instance);
    }
    cout<<"ALLOCATION MATRIX: "<<endl;
    for(int i=0;i<num_proc;i++)
    {
        for(int j=0;j<num_res;j++)
        {
            cout<<"Enter resource instances of resource "<<j+1<<" required for process "<<i+1<<" :"<<endl;
            cin>>allocation[i][j];
        }
    }
     cout<<"MAXIMUM MATRIX: "<<endl;
    for(int i=0;i<num_proc;i++)
    {
        for(int j=0;j<num_res;j++)
        {
            cout<<"Enter maximum demand of resource instances of resource "<<j+1<<" for process "<<i+1<<" :"<<endl;
            cin>>maximum[i][j];
        }
    }
    for(int i=0;i<num_proc;i++)
    {
        for(int j=0;j<num_res;j++)
        {
            need[i][j]=maximum[i][j]-allocation[i][j];
        }
    }
    for(int i=0;i<num_res;i++)
    {
        work[0][i]=available[i];
    }
    safetyalgo(safe);
    cout<<"-----------------------------------------------------"<<endl;
    int p,req;
    cout<<"Request for resource: "<<endl;
    cout<<"Enter process number: "<<endl;
    cin>>p;
    safe=false;
    for(int i=0;i<num_res;i++)
    {
        cout<<"Enter request for resource "<<i+1<<" :"<<endl;
        cin>>req;
        request.push_back(req);
    }
    if(requestalgo(request,safe,p-1))
    {
        cout<<"SAFE SYSTEM!\nRESOURCE CAN BE GRANTED."<<endl;
    }
    else
    {
        cout<<"UNSAFE SYSTEM!\nRESOURCE CANNOT BE GRANTED."<<endl;
    }
}
