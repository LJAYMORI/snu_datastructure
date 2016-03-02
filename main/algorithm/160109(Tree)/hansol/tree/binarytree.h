#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

//노드를 새로 만듦
BTreeNode* MakeBTreeNode(void);
//해당 노드의 값을 반환
BTData GetData(BTreeNode * bt);
//해당 노드의 값을 설정
void SetData(BTreeNode * bt, BTData data);

//왼쪽 자식 노드를반환
BTreeNode* GetLeftSubTree(BTreeNode * bt);
//오른쪽 자식 노드를 반환
BTreeNode* GetRightSubTree(BTreeNode * bt);

//main노드의 왼쪽에 sub노드를 연결
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
//main노드의 오른쪽에 sub노드를 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

//트리 탐색 중 취할 액션
typedef void VisitFuncPtr(BTData data);

//전위, 중위, 후위 순회
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

//모두 탐색하여 data값이 일치하는 노드 반환
BTreeNode* BTreeSearch(BTreeNode* bt, BTData data);

#endif