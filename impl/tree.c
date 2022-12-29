#include "tree.h"

tree *new_branch(tree *root){
        tree *new = (tree*) malloc(sizeof(tree));
        new->left = new->right = NULL;
        root = new;
        return root;
}

tree *tree_append(tree *root, char *data, char *rdata, char *ldata, int depth){
    if(root == NULL){
        root = new_branch(root);
    }
    if(data[depth] != '\0') {
        if (data[depth] == '-') {
                root->left = tree_append(root->left, data, rdata, ldata, depth + 1);
        }
        else if (data[depth] == '.') {
                root->right = tree_append(root->right, data, rdata, ldata, depth + 1);
        }
    }
    if(data[depth] == '\0'){
        strcpy(root->data, rdata);
        strcpy(root->data2, ldata);
    }
    return root;
}

void ftree(tree *root){
    if (root == NULL)
        return;
    ftree(root->left);
    ftree(root->right);
    free(root);
}
