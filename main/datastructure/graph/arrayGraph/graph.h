//
// Created by 김태년 on 2015. 12. 5..
//

#ifndef ARRAY_GRAPH_H
#define ARRAY_GRAPH_H

// 정점의 이름들을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;   // 정점의 수
    int numE;   // 간선의 수
    int**adjArray;   // 간선의 정보
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

#endif
