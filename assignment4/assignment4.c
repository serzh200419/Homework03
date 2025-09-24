#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t c1,c2;int st;
    c1=fork();
    if(c1==0){printf("child1 %d\n",getpid());exit(5);}
    c2=fork();
    if(c2==0){printf("child2 %d\n",getpid());exit(10);}
    pid_t w=waitpid(c1,&st,0);
    if(WIFEXITED(st)) printf("parent: child %d code %d\n",w,WEXITSTATUS(st));
    else printf("parent: child %d abnormal\n",w);
    w=waitpid(c2,&st,0);
    if(WIFEXITED(st)) printf("parent: child %d code %d\n",w,WEXITSTATUS(st));
    else printf("parent: child %d abnormal\n",w);
    return 0;
}


