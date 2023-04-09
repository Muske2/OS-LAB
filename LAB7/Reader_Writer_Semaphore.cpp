#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
sem_t mutex, writeblock;
int rcount = 0;
void *reader(void *arg)
{
    string data;
    ifstream in;
    int reader_id=*((int*)arg);
    sem_wait(&mutex);
    rcount = rcount + 1;
    if (rcount == 1)
        sem_wait(&writeblock);
    sem_post(&mutex);
    in.open("data.txt");
    in >> data;
    cout << "Data read by reader "<<reader_id<<" is "<< data << endl;
    sem_wait(&mutex);
    rcount = rcount - 1;
    in.close();
    if (rcount == 0)
    {
        sem_post(&writeblock);
    }
    sem_post(&mutex);
    const char* fin="OK";
    return (void*)fin;
}

void *writer(void *arg)
{
    ofstream out;
    int writer_id=*((int*)arg);
    sem_wait(&writeblock);
    out.open("data.txt");
    cout << "Data written by writer " << writer_id<<endl;
    out<< "Hello"<<writer_id<< endl;
    out.close();
    sem_post(&writeblock);
    sleep(1);
    const char* fin="OK";
    return (void*)fin;
}
int main()
{
    int i;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);
    for (i = 0; i <= 4; i++)
    {
        pthread_create(&wtid[i], NULL, writer, &i);
        pthread_create(&rtid[i], NULL, reader, &i);
    }
    for (i = 0; i <=2; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    return 0;
}
