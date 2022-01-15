#include "file_read.h"
#include "tree.h"

int file_test(char *file){
    FILE *f;
    if((f = fopen(file,"rt")) == NULL){
        printf("\nA fájl megnyitása sikertelen volt!\n");
        printf("Eredeti kódtábla lesz használva.\n");
        return 0;
    }
    return 1;
}

tree *tread(char *file){
    char *a = (char*) malloc(sizeof(char)*20);
    char *b = (char*) malloc(sizeof(char)*20);
    tree *code_tree = NULL;
    FILE *f;
    if((f = fopen(file,"rt")) == NULL){
        printf("Az fájl megnyitása sikertelen volt!\n");
        exit(1);
    }
    while((fscanf(f,"%s %s", a, b)) != EOF){
        code_tree = tree_append(code_tree, b, a, b, 0);
    }
    fclose(f);
    free(a);
    free(b);
    return code_tree;
}
