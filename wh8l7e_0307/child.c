#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

int i = 0;

    pid_t pid=fork();
    if (pid==0) {
        printf("---Gyermek processz---\n");
        do
        {
            printf("\n Neve: Nagy Bence\nNeptun kód: WH8L7E\n\n");
            i++;

        }while (i<10);

        exit(127);
    }
    else {
        waitpid(pid,0,0);

        printf("---Szülő processz---\n\nA gyermek processz befejezte a 
futását!\n");
    }
    return 0;
}
