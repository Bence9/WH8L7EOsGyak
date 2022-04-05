#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FAJL "wh8l7e.txt"

int main()
{
    int fileHandle = open(FAJL, O_RDWR);

    if(fileHandle == -1)
    {
        printf("Nem sikerult megnyitni a(z) \"%s\" fajlt!\n", FAJL);
        return 1;
    }

    char tartalom[100];

    int beolvas = read(fileHandle, tartalom, sizeof(tartalom));

    tartalom[beolvas] = '\0';
    printf("beolvasott tartalom: \"%s\" osszesen \"%i\" byte.\n", tartalom, beolvas);

    lseek(fileHandle, 0, SEEK_SET);
    printf("A mutato a fajl elejere lett allitva\n");

    char szoveg[] = "Rendszerhivassal iras fajlba";
    int irt = write(fileHandle, szoveg, sizeof(szoveg));
    printf("A fajlba irtuk a(z) \"%s\" szoveget. osszesen \"%i\" byte.\n", szoveg, irt);

    close(fileHandle);

    return 0;
}
