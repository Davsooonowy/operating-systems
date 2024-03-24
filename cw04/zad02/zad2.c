#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int GLOBAL = 0;
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Failed to read 2 arguments\n");
        return -1;
    }

    printf("name of program: %s\n", argv[0]);

    int local = 0;
    pid_t pid = fork();

    if (pid == 0) {
        printf("child process\n");
        GLOBAL++;
        local++;

        printf("child pid = %d, parent pid = %d \n", getpid(), getppid());
        printf("child's local = %d, child's global = %d \n", local, GLOBAL);

        int status = execl("/bin/ls", "ls", "-l", argv[1], NULL);

        exit(status);
    } else {
        int status = 0;
        wait(&status);
        int child_return_status = WEXITSTATUS(status);

        printf("parent process\n");
        printf("parent pid = %d, child pid = %d \n", getpid(), pid);
        printf("Child exit code: %d \n", child_return_status);
        printf("parent's local = %d, parent's global = %d \n", local, GLOBAL);

        return child_return_status;
    }
}