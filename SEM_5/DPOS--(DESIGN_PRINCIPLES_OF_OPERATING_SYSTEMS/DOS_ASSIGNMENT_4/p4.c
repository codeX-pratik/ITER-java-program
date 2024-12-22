#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void generate_fibonacci(int *arr, int length) {
    if (length > 0) arr[0] = 0;
    if (length > 1) arr[1] = 1;

    for (int i = 2; i < length; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int main() {
    int length;
    printf("Enter the length of the Fibonacci series: ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Invalid length. Exiting.\n");
        return 1;
    }
    int *fib_series = (int *)malloc(length * sizeof(int));
    if (fib_series == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        free(fib_series);
        exit(1);
    }

    if (pid == 0) {
        printf("Child Process: Generating Fibonacci series...\n");
        generate_fibonacci(fib_series, length);
        printf("Child Process: Fibonacci series generated.\n");
        exit(0);
    } else {
        wait(NULL); 
        printf("Parent Process: Fibonacci series generated by child:\n");
        for (int i = 0; i < length; i++) {
            printf("%d ", fib_series[i]);
        }
        printf("\n");
        printf("Parent Process: Prime Fibonacci numbers in the series:\n");
        for (int i = 0; i < length; i++) {
            if (is_prime(fib_series[i])) {
                printf("Prime Fibonacci Number: %d at Position: %d\n", fib_series[i], i);
            }
        }
        free(fib_series);
        printf("Parent Process: Task completed.\n");
    }
    return 0;
}


/*

Enter the length of the Fibonacci series: 10
Child Process: Generating Fibonacci series...
Child Process: Fibonacci series generated.
Parent Process: Fibonacci series generated by child:
0 1 1 2 3 5 8 13 21 34
Parent Process: Prime Fibonacci numbers in the series:
Prime Fibonacci Number: 2 at Position: 3
Prime Fibonacci Number: 3 at Position: 4
Prime Fibonacci Number: 5 at Position: 5
Prime Fibonacci Number: 13 at Position: 7
Parent Process: Task completed.


*/