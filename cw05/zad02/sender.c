#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

volatile sig_atomic_t sig_received = 0;

void sigusr1_handler(int signum) {
    sig_received = 1;
    printf("Signal confirmed\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <catcher_pid> <mode>\n", argv[0]);
        return 1;
    }

    signal(SIGUSR1, sigusr1_handler);

    pid_t catcher_pid = atoi(argv[1]);
    int mode = atoi(argv[2]);

    sigset_t mask, oldmask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);

    sigprocmask(SIG_BLOCK, &mask, &oldmask);
    while (!sig_received) {
        sigsuspend(&oldmask);
    }
    sigprocmask(SIG_UNBLOCK, &mask, NULL);

    sigqueue(catcher_pid, SIGUSR1, (union sigval) {mode});
    return 0;
}