#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void megszakit(int sig);
void kilep(int sig);

unsigned int megszakitas = 0;

int main(void)
{
    if (signal(SIGINT, megszakit) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) SIGINT jelre!\n");
        return 0;
    }

    if (signal(SIGQUIT, kilep) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) SIGQUIT jelre!\n");
        return 0;
    }

    while(megszakitas < 2)
    {
        printf("Varakozas a jelre...\n");
        sleep(1);
    }

    printf("Megvan a masodik SIGINT jel!");
    return 0;
}

void megszakit(int jel)
{
    printf("SIGINT jel: %d\n", sig);
    megszakitasok++;
}

void kilep(int jel)
{
    printf("SIGQUIT jel: %d\n", sig);
}
