#define NULL  0
#define N     4        /* N表示图的顶点最大个数         */

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    int data;          /* 注意图的顶点信息是整型        */
    ArcNode *firstarc;
} VNode, Adjlist[N];   /* 最多N个顶点                   */

int visited[N] = {0};  /* 全局变量,初值是0,避免重复遍历 */

typedef struct {
    Adjlist vertices;
    int vexnum, arcnum;
} ALGraph;             /* 邻接表                        */