#include<iostream>
using namespace std;
int main()
{
    int num,framesize,pagefault=0;
    cout<<"Enter number of pages: "<<endl;
    cin>>num;
    cout<<"Enter frame size: "<<endl;
    cin>>framesize;
    cout<<"Enter the pages: "<<endl;
    int page[num],frame[framesize]={0};
    for(int i=0;i<num;i++)
    {
        cin>>page[i];
    }
    bool present;
    for(int i=0;i<num;i++)
    {
        present=false;
        cout<<page[i]<<" ---> ";
        for(int j=0;j<framesize;j++)
        {
            if(page[i]==frame[j])
            {
                present=true;
                break;
            }
        }
        if(!present)
        {
           pagefault++;
            int sel = -1, maxdist = -1,flag=0;
            for(int j=0;j<framesize;j++)
            {
                if(frame[j]==0)
                {
                    frame[j]=page[i];
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(int j=0;j<framesize;j++)
            {
                int dist =99999;
                for(int k=i+1;k<num;k++)
                {
                    if(frame[j]==page[k])
                    {
                        dist = k-i;
                        break;
                    }
                }
                if(dist > maxdist)
                {
                    maxdist = dist;
                    sel = j;
                }
            }
            frame[sel] = page[i];
            }
        }
        for(int j=0;j<framesize;j++)
        {
            if(frame[j]==0)
                continue;
            cout<<frame[j]<<" ";
        }
        cout<<endl;
    }
     cout<<"Total number of page faults: "<<pagefault<<endl;
    cout<<"HIT RATIO: "<<(float)(num-pagefault)/num<<endl;
     cout<<"PAGE FAULT RATIO: "<<(float)(pagefault)/num<<endl;
}
