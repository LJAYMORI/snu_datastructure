#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "binarysearchtree.h"

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot) 
{
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL; 
	BTreeNode * cNode = *pRoot;  
	BTreeNode * nNode = NULL;   

	while (cNode != NULL)
	{
		if (GetData(cNode) == data)
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else 
	{
		*pRoot = nNode;
	}
}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target) 
{
	BTreeNode * cNode = bst;
	BSTData data;

	while (cNode != NULL)
	{
		data = GetData(cNode);

		if (target == data)
			return cNode;
		else if (target < data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}
