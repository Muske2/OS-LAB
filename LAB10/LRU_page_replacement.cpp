#include<iostream>
using namespace std;
int main()
{
    int num,framesize,pagefault=0;
    cout<<"Enter number of pages: "<<endl;
    cin>>num;
    int page[num];
    cout<<"Enter frame size: "<<endl;
    cin>>framesize;
    cout<<"Enter pages: "<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>page[i];
    }
    int counter[20]={0},frame[framesize]={0};
    int cnt=0,mini,flag;
    for(int i=0;i<num;i++)
    {
        cout<<page[i]<<" ---> ";
        bool present=false;
        flag=0;
         for(int j=0;j<framesize;j++)
        {
            if(frame[j]==page[i])
            {
                present=true;
                counter[page[i]]=cnt+1;
                cnt++;
                break;
            }
        }
        if(!present)
        {
            pagefault++;
        for(int j=0;j<framesize;j++)
        {
            if(frame[j]==0)
            {
                frame[j]=page[i];
                counter[page[i]]=cnt+1;
                cnt++;
                flag=1;
                break;
            }
        }
            if(flag==0)
            {
                mini=0;
                for(int j=0;j<framesize;j++)
                {
                    if(counter[frame[mini]]>counter[frame[j]])
                    {
                        mini=j;
                    }
                }
                frame[mini]=page[i];
                counter[page[i]]=cnt+1;
                cnt++;
            }
            for(int n=0;n<framesize;n++)
            {
                if(frame[n]==0)
                    continue;
                cout<<frame[n]<<" ";
            }
        }
        cout<<endl;
        }
         cout << "Total number of page faults: " << pagefault << endl;
    cout << "HIT RATIO: " << (float)(num - pagefault) / num << endl;
    cout << "PAGE FAULT RATIO: " << (float)(pagefault) / num << endl;

}
