#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int valtozo=0;

void novel(int sig);
void kiir(int sig);

int main()
{
    printf("A PID: %d\n", (int)getpid());
    printf("A változó értéke: 0\n");

    while(1){
    signal(SIGUSR1, novel);
    signal(SIGUSR2, kiir);
    pause();
    }
    return 0;
}

void novel(int sig) {
    printf("--- SIGUSR1 ---\n");
    valtozo++;
}
void kiir(int sig) {
    printf("--- SIGUSR2 ---\n");
    printf("A változó értéke: %d\n",valtozo);
}
