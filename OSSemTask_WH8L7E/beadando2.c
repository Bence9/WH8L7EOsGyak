#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv)
{
    pid_t pid;
    if (!(argc>=1)) {
        perror("Nincs kinek");
        exit(1);
    }

    pid = atoi(argv[1]);

    kill(pid, SIGUSR1);
    printf("\nAz első signal elküldve\n");
    sleep(1);
    kill(pid, SIGUSR2);
    printf("A második signal elküldve\n");

    return 0;
}
