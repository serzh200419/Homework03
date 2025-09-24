#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int status;

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        printf("Child (PID=%d) exiting\n", getpid());
        exit(0);
    } else {
        wait(&status);
        printf("Parent (PID=%d) collected child, no zombie\n", getpid());
        sleep(30); 
    }
    return 0;
}

