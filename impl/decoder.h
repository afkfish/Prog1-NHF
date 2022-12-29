#ifndef decoder_h
#define decoder_h

#include "file_read.h"
#include "tree.h"
#include "../debugmalloc.h"

void decode(tree *root);
void encode(tree *root);
void find(char b, tree *root);

#endif
