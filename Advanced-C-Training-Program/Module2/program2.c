#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>

// Global variable for prime calculation
int N;

// ---------------- Signal Handler ----------------
void sigint_handler(int sig) {
    printf("\nSIGINT received but termination is disabled. Program will continue running.\n");
}

// ---------------- Prime Checker ----------------
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

// ---------------- Timer Utility ----------------
double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + 
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

// ---------------- Thread Functions ----------------
void* sum_primes_thread(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int count = 0, num = 2, sum = 0;
    while (count < N) {
        if (is_prime(num)) {
            sum += num;
            count++;
        }
        num++;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Thread A: Sum of first %d prime numbers = %d\n", N, sum);
    printf("Thread A: Execution time = %.3f seconds\n", get_time_diff(start, end));
    return NULL;
}

void* thread1_func(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    time_t t_start = time(NULL);
    while (time(NULL) - t_start < 100) {
        printf("Thread 1 running\n");
        sleep(2);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Thread B: Execution time = %.3f seconds\n", get_time_diff(start, end));
    return NULL;
}

void* thread2_func(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    time_t t_start = time(NULL);
    while (time(NULL) - t_start < 100) {
        printf("Thread 2 running\n");
        sleep(3);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Thread C: Execution time = %.3f seconds\n", get_time_diff(start, end));
    return NULL;
}

// ---------------- Main ----------------
int main() {
    pthread_t threadA, threadB, threadC;

    // Register signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    printf("Enter the value of N (for prime sum): ");
    scanf("%d", &N);

    printf("Starting threads...\n");

    // Launch threads
    pthread_create(&threadA, NULL, sum_primes_thread, NULL);
    pthread_create(&threadB, NULL, thread1_func, NULL);
    pthread_create(&threadC, NULL, thread2_func, NULL);

    // Wait for all threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    printf("All threads completed.\n");
    return 0;
}

