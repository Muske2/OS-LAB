#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#define maxThread 4
pthread_mutex_t lock;
int sum = 0;
int *data;

void *threadSum(void *arg)
{
    int *index;
    index = (int *)arg;
    int localSum = 0;

    pthread_mutex_lock(&lock);
    for (int i = index[0]; i < index[1]; i++)
    {
        localSum += data[i];
    }
    sum += localSum;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    int i;

    sum = 0;
    int n;
    std::cout << "Enter number of items you want: ";
    std::cin >> n;

    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 100;
        data[i] = x;
        std::cout << x <<"   ";
    }

    auto start = std::chrono::high_resolution_clock::now(); //start timer

    pthread_t threads[maxThread];

    for (i = 0; i < maxThread; i++)
    {
        int *index = new int[2];
        index[0] = i * (n / maxThread);
        if (n % maxThread != 0 && i == maxThread - 1)
           index[1] = n;
        else
           index[1] = (i + 1) * (n / maxThread);

        pthread_create(&threads[i], NULL, threadSum, (void *)index);
    }

    for (i = 0; i < maxThread; i++)
        pthread_join(threads[i], NULL);

    auto stop = std::chrono::high_resolution_clock::now(); //stop timer

    double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000000.0;

    std::cout << "\nSum= " << sum;
    std::cout << "\nTime taken: " << duration << " seconds\n";

    return 0;
}

