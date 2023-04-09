#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <algorithm>
// Thread Function declaration

void *BinarySearch(void *arg);
void *LinearSearch(void *arg);
int main()
{

    pthread_t tid_long, t2;
    printf("\nInside main thread before computation \n");
    // Write the code for a linear and binary search  of "50" in 3000 random integers and
    //display the time taken for the search.
    int data[3000];
    for (int i = 0; i < 3000; i++)
    {
        data[i] = rand() % 100;
    }
    // Write the code for the creation of two threads for performing the above linear search
    // using the LinearSearch and BinarySearch  function. Read the documentation for
    // pthread_create, pthread_cancel, and pthread_join.  Display the time taken for the search.
    auto start = std::chrono::steady_clock::now();
    pthread_create(&tid_long, NULL, LinearSearch, (void *)data);
    auto start2 = std::chrono::steady_clock::now();
    pthread_create(&t2, NULL, BinarySearch, (void *)data);
    pthread_join(tid_long, NULL);
    auto end = std::chrono::steady_clock::now();
    std::chrono::nanoseconds diff = end - start;
    std::cout << "Time taken for linear search: " << std::chrono::duration<double, std::milli>(diff).count() << " milliseconds"<<std::endl;
    pthread_join(t2, NULL);
    auto end2 = std::chrono::steady_clock::now();
    auto diff2 = end2 - start2;
    std::cout << "Time taken for binary search: " << std::chrono::duration<double, std::milli>(diff2).count() << " milliseconds"<< std::endl;
    // Analyse the code with different input array size
}

void *LinearSearch(void *arg)
{
    // Write the code for linear search  of 50 in random 3000 integers
    bool found = false;
    int *data = (int *)arg;
    for (int i = 0; i < 3000; i++)
    {
        if (data[i] == 50)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        printf("Linear Found\n");
    }
    else
    {
        printf("Linear Not Found\n");
    }
    return NULL;
}

void *BinarySearch(void *arg)
{
    // Write the code for Binary Search of 50 in random 3000 integers
    bool found = false;
    int *data = (int *)arg;
    for (int i = 0; i <3000; i++)
    {
        for (int j = i + 1; j < 3000; j++)
        {
            if (data[j] < data[i])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    int low = 0;
    int high = 3000-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == 50)
        {
            found = true;
            break;
        }
        else if (data[mid] > 50)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (found)
    {
        printf("Binary Found\n");
    }
    else
    {
        printf("Binary Not Found\n");
    }
    return NULL;
}
