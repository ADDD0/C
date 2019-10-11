#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

void Create(ALGraph *G) {             /* 创建一个有向图                      */
    int i, j, k;
    ArcNode *s;

    printf("Please input vexnum and arcnum:");
    scanf("%d %d", &G->vexnum, &G->arcnum);  /* 输入顶点数(最多N)和边数      */
    printf("Please input each vex message(int) and start with 0:\n");
    for (i = 0; i < G->vexnum; ++i) {
        /* 输入每个顶点信息,注意顶点编号从0开始                              */
        scanf("%d", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    printf("Please input each edge(int):\n");
    for (k = 0; k < G->arcnum; ++k) {
        /* 输入每个边信息,注意录入边的形式                                   */
        scanf("%d,%d", &i, &j);
        s = (ArcNode *) malloc(sizeof(ArcNode));
        s->adjvex = j;
        s->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = s;
    }
}

void DFS(ALGraph G, int v) {  /* 从顶点v出发进行深度优先遍历,注意参数G的类型 */
    ArcNode *w;
    visited[v] = 1;

    printf("%3d", G.vertices[v].data);
    for (w = G.vertices[v].firstarc; w; w = w->nextarc)
        if (!visited[w->adjvex])
            DFS(G, w->adjvex);
}

void DFSGraph(ALGraph G) {            /* 尝试从各点出发DFS                   */
    int i;

    for (i = 0; i < G.vexnum; ++i)
        if (!visited[i]) {
            printf("\nFrom %d DFS is:", i);
            DFS(G, i);                /* 从i出发深度遍历                     */
        }
}

int OutputDegree(ALGraph G, int i) {  /*返回编号是i的顶点的出度              */
    ArcNode *w;
    int n=0;

    for (w = G.vertices[i].firstarc; w; w = w->nextarc)
        if (w)
            ++n;
    return n;
}

int InDegree(ALGraph G, int i) {      /*返回编号是i的顶点的入度              */
    ArcNode *w;
    int j, n=0;

    for (j = 0; j < G.vexnum; ++j)
        for (w = G.vertices[j].firstarc; w; w = w->nextarc)
            if (w->adjvex == i) {
                ++n;
                break;
            }
    return n;
}

int main(){
    ALGraph G;

    Create(&G);
    DFSGraph(G);
    printf("\n%d\n", OutputDegree(G, 0));
    printf("%d\n", InDegree(G, 0));
    return 0;
}