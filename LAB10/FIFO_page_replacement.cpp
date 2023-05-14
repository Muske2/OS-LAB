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
    int k=0;
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
            if(k==framesize)
            {
                k=0;
                frame[k]=page[i];
                k++;
            }
            else
            {
                frame[k]=page[i];
                k++;
            }
            for(int j=0;j<framesize;j++)
            {
                if(frame[j]==0)
                    continue;
                cout<<frame[j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"Total number of page faults: "<<pagefault<<endl;
    cout<<"HIT RATIO: "<<(float)(num-pagefault)/num<<endl;
     cout<<"PAGE FAULT RATIO: "<<(float)(pagefault)/num<<endl;
}
