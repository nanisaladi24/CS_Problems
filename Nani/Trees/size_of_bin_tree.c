#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

void size_bin_tree(node *root, int *count){
    if (root==NULL)
        return;
    else{
        (*count)++;
        size_bin_tree(root->left,count);
        size_bin_tree(root->right,count);
    }
    return;
}

int main(){
    //printf("hello");
    node *root=NULL;
    root = (node *)malloc(sizeof(node));
    root->data=10;
    root->left=(node *)malloc(sizeof(node));
    root->right=(node *)malloc(sizeof(node));
    root->left->data=20;
    root->right->data=30;
    root->left->left=NULL;
    root->left->right=NULL;
    root->right->left=NULL;
    root->right->right=NULL;
    //printf ("%d",root->data);

    int count=0;
    size_bin_tree(root,&count);
    printf ("\nSize of Tree: %d",count);
    return 0;
}