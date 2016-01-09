#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "binarysearchtree.h"

typedef BTData BSTData;

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot) {
    BTreeNode *node = (BTreeNode *) malloc(sizeof(BTreeNode));
    node->right = NULL;
    node->left = NULL;

    *pRoot = node;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst) {
    return bst->data;
}

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data) {
    BTreeNode *compareNode = *pRoot;

    BTreeNode *node = (BTreeNode *) malloc(sizeof(BTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    while (compareNode != NULL) {
        if (compareNode->data > data) {
            if (compareNode->left == NULL) {
                compareNode->left = node;
                return;

            } else {
                compareNode = compareNode->left;
            }

        } else if (compareNode->data < data) {
            if (compareNode->right== NULL) {
                compareNode->right = node;
                return;

            } else {
                compareNode = compareNode->right;
            }

        } else {
            return;
        }
    }
}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target) {
    while (bst != NULL) {
        if (bst->data > target) {
            bst = bst->left;
        } else if (bst->data < target) {
            bst = bst->right;
        } else {
            return bst;
        }
    }
    return NULL;
}