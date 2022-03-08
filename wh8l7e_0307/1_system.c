#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
//pico 1_sytem.c
//cc 1_system.c -o 1_system.out

int main()
{
    int status;

    if((status = system("date"))<0)
        perror("system() error");

    if(WIFEXITED(status))
        printf("Neptunkod: wh8l7e ,visszaadott erteke =%d\n", WEXITSTATUS(status));

    exit(0);
}
