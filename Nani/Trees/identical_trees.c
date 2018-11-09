#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

void indentical_tree(node *root, node *root1, int *isTrue){
    if (root==NULL && root1==NULL)
        return;
    if ((root==NULL && root1!=NULL)||(root!=NULL && root1==NULL)){
        *isTrue=0;
        return;
    }
    else{
        if (root->data!=root1->data){
            *isTrue=0;
            return;
        }
        else{
            indentical_tree(root->left, root1->left, isTrue);
            indentical_tree(root->right, root1->right, isTrue);            
        }
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

    node *root1=NULL;
    root1 = (node *)malloc(sizeof(node));
    root1->data=10;
    root1->left=(node *)malloc(sizeof(node));
    root1->right=(node *)malloc(sizeof(node));
    root1->left->data=20;
    //root1->left->data=40; // testing non-identical trees
    root1->right->data=30;
    root1->left->left=NULL;
    root1->left->right=NULL;
    root1->right->left=NULL;
    root1->right->right=NULL;

    int isTrue=1;
    indentical_tree(root,root1,&isTrue);
    if (isTrue)
        printf("\nThey are identical trees");
    else
        printf ("\nThey are not identical trees");
    return 0;
}