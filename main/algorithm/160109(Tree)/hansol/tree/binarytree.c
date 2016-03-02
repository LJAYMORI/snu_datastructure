#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

BTreeNode* MakeBTreeNode(void) {
	BTreeNode* node = (BTreeNode*) malloc(sizeof(BTreeNode));
	node->left = NULL;
	node->right = NULL;
	return node;
}
BTData GetData(BTreeNode * bt) {
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode * bt) {
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode * bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if(bt != NULL) {
		action(bt->data);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}
}
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if(bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->data);
		InorderTraverse(bt->right, action);
	}
}
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if(bt != NULL) {
		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->data);
	}
}

BTreeNode* BTreeSearch(BTreeNode* bt, BTData target) {
	if(bt->data == target)
		return bt;

	if(bt->left != NULL)
		BTreeSearch(bt->left, target);
	if(bt->right != NULL)
		BTreeSearch(bt->right, target);
}