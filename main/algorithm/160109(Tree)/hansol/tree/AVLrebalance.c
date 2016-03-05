#include <stdio.h>
#include "binarytree.h"
/*
* AVLTree: 오른쪽과 왼쪽의 서브트리의 깊이의 균형을 맞춘 트리
* 균형인수 = 왼쪽 서브트리 깊이 - 오른쪽 서브트리 깊이
* 균형인수가 2 이상일때 트리 재조정
* 재조정 방법
* 1. LL회전 
*	- cNode의 오른쪽자식을 pNode의 왼쪽자식으로 이동
*	- pNode를 cNode의 오른쪽자식으로 이동
* 2. RR회전
*	- cNode의 왼쪽자식을 pNode의 오른쪽자식으로 이동
*	- pNode를 cNode의 왼쪽자식으로 이동 
* 3. LR회전
*	- cNode 중심으로 부분 RR회전
*	- LL회전
* 4. RL회전
*	- cNode 중심으로 부분 LL회전
*	- RR회전
*/

BTreeNode * RotateLL(BTreeNode * bst){
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);
	return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst){
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);
	return cNode;
}

BTreeNode * RotateRL(BTreeNode * bst){
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode)); 
	return RotateRR(pNode); 
}

BTreeNode * RotateLR(BTreeNode * bst){
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);  
}

int GetHeight(BTreeNode * bst) {
	int leftH;	
	int rightH;	

	if(bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst){
	int lsh; 
	int rsh;  

	if(bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode ** pRoot){
	int hDiff = GetHeightDiff(*pRoot);

	if(hDiff > 1) {
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}
	
	if(hDiff < -1) {
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	
	return *pRoot;
}