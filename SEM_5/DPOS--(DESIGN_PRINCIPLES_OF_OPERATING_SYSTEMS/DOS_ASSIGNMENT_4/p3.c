#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define FILE1 "file1.txt"
#define FILE2 "file2.txt"

void copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "r");
    FILE *dest_file = fopen(dest, "w");

    if (!src_file || !dest_file) {
        perror("File open error");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_file)) {
        fputs(buffer, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void display_file(const char *file) {
    FILE *f = fopen(file, "r");
    if (!f) {
        perror("File open error");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), f)) {
        printf("%s", buffer);
    }
    fclose(f);
}

void display_sorted_reverse(const char *file) {
    FILE *f = fopen(file, "r");
    if (!f) {
        perror("File open error");
        exit(1);
    }
    char *lines[100];
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), f)) {
        lines[count] = strdup(buffer);
        count++;
    }
    fclose(f);
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
}

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid1 == 0) {
        printf("First Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        copy_file(FILE1, FILE2);
        printf("First Child: Copied content from %s to %s\n", FILE1, FILE2);
        exit(0);
    }
    sleep(1);
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid2 == 0) {
        printf("Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Second Child: Displaying content of %s\n", FILE2);
        display_file(FILE2);
        exit(0);
    }
    sleep(1);

    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid3 == 0) {
        printf("Third Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Third Child: Displaying sorted content of %s in reverse order\n", FILE2);
        display_sorted_reverse(FILE2);
        exit(0);
    }
    sleep(1);
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }
    printf("Parent Process: PID = %d\n", getpid());
    printf("Parent Process: All child processes have completed.\n");

    return 0;
}

/*

First Child: PID = 577, Parent PID = 576
File open error: No such file or directory
Second Child: PID = 578, Parent PID = 576
Second Child: Displaying content of file2.txt
Third Child: PID = 579, Parent PID = 576
Third Child: Displaying sorted content of file2.txt in reverse order
Parent Process: PID = 576
Parent Process: All child processes have completed.

*/