//
// Created by 김태년 on 2016. 1. 9..
//

#include <stdlib.h>
#include "binarytree.h"

BTreeNode * MakeBTreeNode(void){
    return (BTreeNode*)malloc(sizeof(BTreeNode));
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