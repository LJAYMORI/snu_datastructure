#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "../../list/linkedlist/doublylinkedlist/dlinkedlist.h"

// 정점의 이름들을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;   // 정점의 수
	int numE;   // 간선의 수
	List * adjList;   // 간선의 정보
	int * visitInfo;
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// Depth First Search: 정점의 정보 출력
void DFShowGraphVertex(ALGraph * pg, int startV);

#endif