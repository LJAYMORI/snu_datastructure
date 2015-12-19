#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define VERTEX_COUNT 5

typedef struct edge {
	int start;
	int end;
	int weight;
} Edge;

int comp(const void *x, const void *y);

void Union(const int i, const int j);

int SimpleFind(const int i);

void Kruskal(Edge *edge, Edge *selectEdge);

void edgePrint(Edge selectEdge[VERTEX_COUNT]);

int up[SIZE];
int weight[SIZE];

int main() {
	int i;
	Edge edge[] = {
		{ 1, 2, 1 },
		{ 1, 3, 3 },
		{ 2, 3, 3 },
		{ 2, 4, 6 },
		{ 3, 4, 4 },
		{ 3, 5, 2 },
		{ 4, 5, 5 }
	};
	Edge selectEdge[VERTEX_COUNT] = { 0, 0, 0 };

	qsort(edge, sizeof(edge) / sizeof(edge[0]), sizeof(Edge), comp);

	for (i = 1; i < SIZE; i++) {
		up[i] = 0;
		weight[i] = 1;
	}

	Kruskal(edge, selectEdge);
	edgePrint(selectEdge);

	return 0;
}

int comp(const void *x, const void *y) {
	return ((Edge *)x)->weight - ((Edge *)y)->weight;
}

void Union(const int i, const int j) {
	int rooti = SimpleFind(i);
	int rootj = SimpleFind(j);

	if (weight[rooti] > weight[rootj]) {
		up[rootj] = rooti;
		weight[rooti] = weight[rooti] + weight[rootj];
		weight[rootj] = 0;
	}
	else if (weight[rooti] < weight[rootj]) {
		up[rooti] = rootj;
		weight[rootj] = weight[rooti] + weight[rootj];
		weight[rooti] = 0;
	}
	else if (weight[rooti] == weight[rootj]) {
		if (rooti > rootj) {
			up[rootj] = rooti;
			weight[rooti] = weight[rooti] + weight[rootj];
			weight[rootj] = 0;
		}
		else {
			up[rooti] = rootj;
			weight[rootj] = weight[rooti] + weight[rootj];
			weight[rooti] = 0;
		}
	}
}

int SimpleFind(const int i) {
	int root = i;

	while (up[root] > 0)
		root = up[root];

	return root;
}

void Kruskal(Edge *edge, Edge *selectEdge) {
	int selectVertexCnt = 0, edgeCnt = 0;

	while (selectVertexCnt < VERTEX_COUNT - 1) {
		int x = edge[edgeCnt].start, y = edge[edgeCnt].end;
		int p = SimpleFind(x);
		int q = SimpleFind(y);

		if (q != p) {
			Union(q, p);
			selectEdge[selectVertexCnt].start = edge[edgeCnt].start;
			selectEdge[selectVertexCnt].end = edge[edgeCnt].end;
			selectEdge[selectVertexCnt].weight = edge[edgeCnt].weight;
			selectVertexCnt++;
		}
		edgeCnt++;
	}
}

void edgePrint(Edge selectEdge[VERTEX_COUNT]) {
	int i;

	printf("Minimum Spanning Trees\n");
	printf("Kruskal's Algorithm\n");
	for (i = 0; i < VERTEX_COUNT - 1; i++)
		printf("Start : %d End : %d Weight : %d\n", selectEdge[i].start, selectEdge[i].end, selectEdge[i].weight);
}
