#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <iostream>
#define MAXCAPACITY 2
using namespace std;
int buff[MAXCAPACITY];
sem_t mutex,full,empt;
int in = 0, out = 0;
int item = 0;
void *produce(void *);
void *consume(void *);

void *produce(void *arg)//In the context of pthreads,
                        // the thread function is expected to return a void* value, which is a pointer to any data type.
                        // This allows the thread function to return any type of data that can be pointed to by a pointer.
{
    sem_wait(&empt);
    sem_wait(&mutex);
    item++;
    buff[in] = item;
    cout<<"Produced data "<<buff[in];
    in = (in + 1) % MAXCAPACITY;
    sem_post(&mutex);
    sem_post(&full);
    //sleep(1);
    const char *test = "hello";
    return (void *)test;
}

void *consume(void *arg)
{
    int citem = 0;
    sem_wait(&full);
    sem_wait(&mutex);
    //sleep(2);
    citem = buff[out];
    printf(" Consumed Data = %d\n", buff[out]);
    out = (out + 1) % MAXCAPACITY;
    sem_post(&mutex);
    sem_post(&empt);
    //sleep(2);
    const char *test = "hello";
    return (void *)test;
}

int main(int argc, const char *argv[])
{
    in = 0, out = 0;
    int i, NumThreads;
    NumThreads = 6;
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empt, 0, MAXCAPACITY);
    pthread_t producers[NumThreads], consumers[NumThreads];
    for (i = 0; i < NumThreads; i++)
    {
        pthread_create(&producers[i], NULL, produce, NULL);
        pthread_create(&consumers[i], NULL, consume, NULL);
    }
    for (i = 0; i < NumThreads; i++)
    {
        void *p = NULL;
        pthread_join(producers[i], &p);
        cout << (char *)p << endl;
        pthread_join(consumers[i], &p);
        cout << (char *)p << endl;
    }

    return 0;
}
