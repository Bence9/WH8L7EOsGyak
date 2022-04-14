#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int fd;
    pid_t gyerek;

    if((mkfifo("WH8L7E", S_IRUSR | S_IWUSR)) < 0)
	{
        printf("Nem sikerult a FIFO letrehozasa!\n");
        exit(1);
	}

    if((gyerek = fork()) < 0){
        printf("Nem sikerult a gyerek fork processz letrehozasa!\n");
        exit(1);
    }
	else
	{
		printf("A gyerek processz elindult!\n");
	}

    //Gyerek processz
    if(!gyerek){
        char *uzenet = "Nagy Bence";


        if((fd = open("WH8L7E", O_WRONLY)) < 0){
            printf("Nem sikerult a FIFO megnyitasa!\n");
            exit(1);


        } else {

            printf("FIFO megnyitva csak irasra\n");
            write(fd, uzenet, strlen(uzenet));

        }
        printf("A gyerek processz sikeresen befejezete az irast,\na gyerek processz kilep.\n");
		printf("Szulo processz inditasa\n");
    }

    //Szulo processz
    if(gyerek){
        char buf[256];
        if((fd = open("WH8L7E", O_RDONLY)) <0 ){

            printf("Nem sikerult a FIFO megnyitasa!\n");
            exit(1);

        } else {

            printf("FIFO megnyitva csak olvasasra, olvasas folyamatban...\n");
            read(fd, buf, sizeof(buf));
            printf("Kiolvasott adat: %s.\n\n", buf);

            printf("A szulo processz sikeresen befejezete az olvasast.\n");

        }
        if((unlink("WH8L7E")) < 0 || (close(fd)) < 0){

            printf("RENDSZER: Nem sikerult a FIFO torlese!");

        } else {

            printf("RENDSZER: FIFO sikeresen torolve, kilepes.\n");
        }
	}

    return 0;
}
