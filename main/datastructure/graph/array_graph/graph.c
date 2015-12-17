//
// Created by 김태년 on 2015. 12. 5..
//

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

// 그래프의 초기화
void GraphInit(ALGraph *pg, int nv) {
    int i=0;
    int j=0;

    pg->numV = nv;
    pg->numE = 0;

    pg->adjArray = (int**) malloc (sizeof(int*) * nv);

    for(i=0; i<nv; i++){
        pg->adjArray[i] = (int*) malloc (sizeof(int) * nv);
        for(j=0; j<nv; j++){
            pg->adjArray[i][j] = 0;
        }
    }
}

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg) {
    if(pg->adjArray != NULL) {
        free(pg->adjArray);
    }
}

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV) {
    pg->adjArray[fromV][toV] = 1;
    pg->adjArray[toV][fromV] = 1;
    pg->numE++;
}

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg) {
    int i;
    int j;

    for(i=0 ; i < pg->numV ; i++){
        printf("%c와 연결된 정점: ", i + 65);
        for(j=0 ; j< pg->numV ; j++) {
            if(pg->adjArray[i][j] == 1) {
                printf("%c ", j + 65);
            }
        }
        printf("\n");
    }
}
