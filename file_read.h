#ifndef file_read_h
#define file_read_h
#include "tree.h"
#include "debugmalloc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tree *tread(char *file);
int file_test(char *file);

#endif
