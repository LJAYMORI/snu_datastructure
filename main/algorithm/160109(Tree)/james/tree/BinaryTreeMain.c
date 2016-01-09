#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * node = (BTreeNode*)malloc(sizeof(BTreeNode));

	node->left = NULL;
	node->right = NULL;
	return node;
}

BTData GetData(BTreeNode * node)
{
	return node->data;
}

void SetData(BTreeNode * node, BTData data)
{
	node->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * node)
{
	return node->left;
}

BTreeNode * GetRightSubTree(BTreeNode * node)
{
	return node->right;
}

void MakeLeftSubTree(BTreeNode * parent, BTreeNode * sub)
{
	if (parent->left != NULL)
		free(parent->left);

	parent->left = sub;
}

void MakeRightSubTree(BTreeNode * parent, BTreeNode * sub)
{
	if (parent->right != NULL)
		free(parent->right);

	parent->right = sub;
}

void PreorderTraverse(BTreeNode * node, VisitFuncPtr vptr)
{
	if (node == NULL)
		return;

	vptr(node->data);
	PreorderTraverse(node->left, vptr);
	PreorderTraverse(node->right, vptr);
}

void InorderTraverse(BTreeNode * node, VisitFuncPtr vptr)
{
	if (node == NULL)
		return;

	InorderTraverse(node->left, vptr);
	vptr(node->data);
	InorderTraverse(node->right, vptr);
}

void PostorderTraverse(BTreeNode * node, VisitFuncPtr vptr)
{
	if (node == NULL)
		return;

	PostorderTraverse(node->left, vptr);
	PostorderTraverse(node->right, vptr);
	vptr(node->data);
}

BTreeNode * RemoveLeftSubTree(BTreeNode * node)
{
	BTreeNode * delNode;

	if (node != NULL) 
	{
		delNode = node->left;
		node->left = NULL;
	}
	return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * node)
{
	BTreeNode * delNode;

	if (node != NULL) 
	{
		delNode = node->right;
		node->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * parent, BTreeNode * sub)
{
	parent->left = sub;
}

void ChangeRightSubTree(BTreeNode * parent, BTreeNode * sub)
{
	parent->right = sub;
}
