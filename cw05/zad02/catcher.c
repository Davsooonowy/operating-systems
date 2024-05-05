#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int signals_cnt = 0;
volatile int status = 0;

void sigusr1_handler(int signum, siginfo_t* info, void *context) {
    signals_cnt++;
    status = info->si_int;
    printf("Signal %d sent by PID: %d\n", status, info->si_pid);
    kill(info->si_pid, SIGUSR1);
}

int main() {
    printf("Catcher PID: %d\n", getpid());
    struct sigaction act;
    act.sa_sigaction = sigusr1_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);

    printf("Catcher PID: %d\n", getpid());

    while (1) {
        pause();
        switch (status) {
            case 1:
                for (int i=1; i<=100; i++) {
                    printf("%i ", i);
                }
                printf("\n");
                break;
            case 2:
                printf("Received %d signals\n", signals_cnt);;
                break;
            case 3:
                exit(0);
            default:
                fprintf(stderr, "Invalid mode: %d\n", status);
                break;
        }
    }
}