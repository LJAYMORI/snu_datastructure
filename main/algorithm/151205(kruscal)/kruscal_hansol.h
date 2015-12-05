#ifndef __HANSOL_KRUSKAL__
#define __HANSOL_KRUSKAL__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define V_SIZE	11111
#define E_SIZE 	111111
#define TRUE	1
#define FALSE	0

typedef int BOOL;
typedef enum{weight, v_from, v_to} ENUM_EDGE;

int graph[V_SIZE][V_SIZE];
int edge[E_SIZE][3];
int vcnt, ecnt;
int v1, v2, w;

// bfs
BOOL visited[V_SIZE];


// quick sort
void swap(int (*arr)[3], int idx1, int idx2);
int partition(int (*arr)[3], int left, int right);
void quicksort(int (*arr)[3], int left, int right);

// check path
BOOL check_path(BOOL *visited);

#endif