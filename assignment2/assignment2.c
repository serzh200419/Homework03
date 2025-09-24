#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t c1,c2;
    int st;

    c1=fork();
    if(c1<0){printf("err\n");exit(1);}
    else if(c1==0){
        printf("child1 pid=%d\n",getpid());
        exit(10);
    }

    c2=fork();
    if(c2<0){printf("err\n");exit(1);}
    else if(c2==0){
        printf("child2 pid=%d\n",getpid());
        exit(20);
    }

    printf("parent pid=%d\n",getpid());

    pid_t w=wait(&st);
    if(WIFEXITED(st)) printf("parent: child %d exit %d\n",w,WEXITSTATUS(st));

    pid_t w2=waitpid(c2,&st,0);
    if(WIFEXITED(st)) printf("parent: child %d exit %d\n",w2,WEXITSTATUS(st));

    return 0;
}

