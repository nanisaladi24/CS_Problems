
//
//  main.c
//  Trees
//
//  Created by raghav on 11/8/18.
//  Copyright © 2018 raghav. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
static int size =1;  // 1 because i am not counting root in traversing left and right sub trees.

//structure of the node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node ->right=NULL;
    return node;
}
void inorder(struct node* root){
    if((*root).data!=NULL){
        if(root->left!=NULL){
            size++;inorder(root->left);
        }
        if(root->right!=NULL){
            size++;inorder(root->right);
        }
    }
}
int main(int argc, const char * argv[]) {
    struct node *root = newNode(1);
    root->left =newNode(2);
    root->left->left=newNode(3);
    root->left->right =newNode(4);
    root->right=newNode(5);
    root->right->left =newNode(6);
    root->right->right=newNode(7);
    inorder(root);
    printf("size of the tree is %d \n",size);
    return 0;
}
