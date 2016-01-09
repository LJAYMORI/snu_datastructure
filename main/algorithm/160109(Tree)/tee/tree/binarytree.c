//
// Created by 김태년 on 2016. 1. 9..
//

#include <stdlib.h>
#include "binarytree.h"

BTreeNode * MakeBTreeNode(void){
    BTreeNode* bTreeNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    bTreeNode->right = NULL;
    bTreeNode->right = NULL;
    return bTreeNode;
}

BTData GetData(BTreeNode * bt){
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data){
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt){
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
    main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if(bt != NULL) {
        action(bt->data);
        PreorderTraverse(bt->left, action);
        PreorderTraverse(bt->right, action);
    }
}
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if(bt != NULL) {
        InorderTraverse(bt->left, action);
        action(bt->data);
        InorderTraverse(bt->right, action);
    }
}
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if(bt != NULL) {
        PostorderTraverse(bt->left, action);
        PostorderTraverse(bt->right, action);
        action(bt->data);
    }
}