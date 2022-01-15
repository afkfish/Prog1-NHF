#include "decoder.h"
#include "file_read.h"
#include "debugmalloc.h"
#include <string.h>
#include <stdio.h>

int main(){
    int b;
    tree *tree;
    char file[256] = {"kodtabla.txt"};
    printf(
    "--morze: morze dekódolása\n"
    "--ascii: rendes szöveg morzévé alakítása\n"
    "--newt: új kódkészlet helyének megadása\n"
    "--help: help menű megnyitása\n"
    "--exit: kilépés a programból\n"
    );
    do
    {
        char a[20];
        b = 0;
        tree = tread(file);
        printf("\nParancs:");
        scanf(" %20s", a);
        printf("\n");
        if(strcmp(a, "--morze") == 0) b = 1;
        else if(strcmp(a, "--ascii") == 0) b = 2;
        else if(strcmp(a, "--newt") == 0) b = 3;
        else if(strcmp(a, "--help") == 0) b = 4;
        else if(strcmp(a, "--exit") == 0) b = 9;
        else b = 4;
        switch (b)
        {
        case 1:
            decode(tree);
            break;
        case 2:
            encode(tree);
            break;
        case 3:
            printf("A beolvasni kívánt kódtábla helye: ");
            scanf(" %256s", file);
            ftree(tree);
            if(file_test(file) == 0){
                strcpy(file, "kodtabla.txt\0");
            }
            break;
        case 4:
            printf(
            "--morze: morze dekódolása\n"
            "--ascii: rendes szöveg morzévé alakítása\n"
            "--newt: új kódkészlet helyének megadása\n"
            "--help: help menű megnyitása\n"
            "--exit: kilépés a programból\n"
            );
            break;
        default:
            break;
        }
    } while (b != 9);
    ftree(tree);
    return 0;
}
