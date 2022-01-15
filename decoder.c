#include "decoder.h"

void decode(tree *root){
    printf("A dekódolni kívánt szöveg: ");
    char b[256];
    int char_err = 0;
    int i = 0;
    scanf(" %[^\n]", b);
    strcpy(b+strlen(b), " \0");
    printf("\nDekódolt szöveg: ");
    tree *mover = root;
    while(b[i] != '\0'){
        if(b[i] == '.' || b[i] == '-') {
            if (b[i] == '-' && mover != NULL) {
                mover = mover->left;
                i++;
            }
            else if (b[i] == '.' && mover != NULL) {
                mover = mover->right;
                i++;
            }
            else i++;
        }
        else{
            if(mover == NULL){
                printf("§");
                char_err = 1;
            }
            else {
                printf("%s", mover->data);
            }
            mover = root;
            printf("%c", b[i]);
            i++;
        }
    }
    if(char_err) {
        printf("\n\nA lefordított szövegben § található, mert olyan karakter(ek) volt(ak) megadva ami(k) nem szerepelt(ek) a dekódoló fájlban.\n");
    }
    else {
        printf("\n");
    }
}

void encode(tree *root){
    char b[256];
    printf("A kódolni kívánt szöveg: ");
    scanf(" %[^\n]", b);
    printf("\n");
    for(int i = 0; b[i] != '\0'; i++){
        if(b[i] >= 90 && b[i] <= 122){
            b[i] = b[i]-32;
        }
        find(b[i], root);
        printf(" ");
    }
    printf("\n");
}

void find(char b, tree *root){
    if (root == NULL)
        return;
    if(b == root->data[0]){
        printf("%s", root->data2);
        return;
    }
    find(b, root->left);
    find(b, root->right);
}
