#ifndef decoder_tree_h
#define decoder_tree_h

#include "debugmalloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tree{
    char data[20];
    char data2[20];
    struct tree *left, *right;
} tree;

tree *new_branch(tree *root);
tree *tree_append(tree *root, char *data, char *rdata, char *ldata, int depth);
void ftree(tree *root);

#endif
