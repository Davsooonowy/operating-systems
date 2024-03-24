#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Failed to read 2 arguments\n");
        return -1;
    }
    long n_of_processes = atol(argv[1]);

    if (n_of_processes < 0) {
        printf("Number of processes must be greater than 0\n");
        return -1;
    }

    for (int i = 0; i < n_of_processes; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("%d\n", i + 1);
            printf("Child process %d\n", getpid());
            printf("Parent process %d\n", getppid());
            printf("\n");
            exit(0);
        }
    }

    while(wait(NULL) > 0);
    printf("Number of processes: %ld\n ", n_of_processes);
    return 0;
}