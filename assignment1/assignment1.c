#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t p = fork();
    if (p < 0) {
        printf("fork error\n");
        exit(1);
    } else if (p == 0) {
        printf("child pid: %d\n", getpid());
        exit(0);
    } else {
        printf("parent pid: %d\n", getpid());
    }
    return 0;
}

