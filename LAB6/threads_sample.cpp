#include<iostream>
#include<thread>
#include<vector>
#include<stdlib.h>
//Sample code to create two threads to add and multiply
void add(const int *data,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=data[i];
    }
    std::cout<<"SUM: "<<sum<<std::endl;
}
void multiply(const int* data,int n)
{
    long mult=1;
    for(int i=0;i<n;i++)
    {
        mult=mult*data[i];
    }
    std::cout<<"PRODUCT: "<<mult<<std::endl;
}
int main()
{
    int n;
    std::cout<<"Enter number of terms: "<<std::endl;
    std::cin>>n;
    std::vector<int>data(n);
    for(int i=0;i<n;i++)
    {
        data[i]=rand()%100;
    }
    std::cout<<"TERMS:\n";
    for(int i=0;i<n;i++)
    {
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
    std::thread A(add,data.data(),n);
    std::thread B(multiply,data.data(),n);
    A.join();
    B.join();
}
