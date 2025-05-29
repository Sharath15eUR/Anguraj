#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

int N; // Number of prime numbers to sum

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

// Thread A: Calculate the sum of first N prime numbers
void* sum_primes(void* arg) {
    int count = 0, num = 2, sum = 0;
    while (count < N) {
        if (is_prime(num)) {
            sum += num;
            count++;
        }
        num++;
    }
    printf("Sum of first %d prime numbers is: %d\n", N, sum);
    return NULL;
}

// Thread B: Print "Thread 1 running" every 2 seconds for 100 seconds
void* thread1_func(void* arg) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 100) {
        printf("Thread 1 running\n");
        sleep(2);
    }
    return NULL;
}

// Thread C: Print "Thread 2 running" every 3 seconds for 100 seconds
void* thread2_func(void* arg) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 100) {
        printf("Thread 2 running\n");
        sleep(3);
    }
    return NULL;
}

int main() {
    pthread_t threadA, threadB, threadC;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Create threads
    pthread_create(&threadA, NULL, sum_primes, NULL);
    pthread_create(&threadB, NULL, thread1_func, NULL);
    pthread_create(&threadC, NULL, thread2_func, NULL);

    // Wait for all threads to complete
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    return 0;
}

