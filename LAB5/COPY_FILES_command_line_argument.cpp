#include<iostream>
using namespace std;
int main(int argc,char *arg[])
{
    cout<<"COPYING FILES"<<endl;
    FILE *f1,*f2;
    f1=fopen(arg[1],"r");
    f2=fopen(arg[2],"w");
    if(!f1 || !f2 || argc!=3)
    {
        cout<<"ERROR"<<endl;
    }
    char c;
    while((c=fgetc(f1))!=EOF)//EOF=End Of File
    {
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
}
