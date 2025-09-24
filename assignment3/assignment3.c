#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void f1(){printf("f1 called\n");}
void f2(){printf("f2 called\n");}

int main(){
    atexit(f1);
    atexit(f2);
    printf("main run pid=%d\n",getpid());
    exit(0);
    printf("end main\n");
    return 0;
}

