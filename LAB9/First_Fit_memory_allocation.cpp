#include<iostream>
using namespace std;
struct memory
{
    int id;
    int size;
    int rem;
    bool allocated;
};
int main()
{
    int num_holes,num_process;
    cout<<"Enter number of holes: "<<endl;
    cin>>num_holes;
    cout<<"Enter number of processes: "<<endl;
    cin>>num_process;
    memory hole[num_holes];
    memory process[num_process];
    for(int i=0;i<num_holes;i++)
    {
        cout<<"Enter size of hole H"<<i<<" : "<<endl;
        cin>>hole[i].size;
        hole[i].rem=hole[i].size;
        hole[i].allocated=false;
    }
    for(int i=0;i<num_process;i++)
    {
        cout<<"Enter size of process P"<<i<<" : "<<endl;
        cin>>process[i].size;
        process[i].allocated=false;
        process[i].id=-1;
    }
    for(int i=0;i<num_process;i++)
    {
       for(int j=0;j<num_holes;j++)
       {
           if(process[i].size<=hole[j].rem)
           {
               hole[j].rem-=process[i].size;
               process[i].allocated=true;
               process[i].id=j;
               hole[j].allocated=true;
               break;
           }
       }
    }
    cout<<"--------------------------------------------------------------------------------------"<<endl;
  cout<<"Process "<<"\tAllocated Holes \tUnallocated Status "<<endl;
  for(int i=0;i<num_process;i++)
  {
  cout<<"P"<<i<<"\t\t";
    if(!process[i].allocated)
    {
      cout<<process[i].id<<"\t\t\tNot currently allocated\t"<<endl;
    }
    else
    {
      cout<<process[i].id<<"\t\t\tAllocated\t"<<endl;
    }
  }
  cout<<"--------------------------------------------------------------------------------------"<<endl;
  cout<<"Memory hole "<<"\tstatus "<<"\tActual availability"<<"\tCurrent availabilty"<<endl;
  for(int i=0;i<num_holes;i++)
  {
    cout<<"H"<<i<<"\t\t";
    if(!hole[i].allocated)
    {
      cout<<"Free\t\t"<<hole[i].size<<"\t\t"<<hole[i].rem<<endl;
    }
    else
    {
      cout<<"Busy\t\t"<<hole[i].size<<"\t\t"<<hole[i].rem<<endl;
    }
  }
}
