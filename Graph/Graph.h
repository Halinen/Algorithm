#pragma once
#include<queue>
#define MAX_VERTEX_NUM 20  //最大顶点数

class ArcNode {
public:
	int adjvex;//该弧指向的顶点位置
	ArcNode *nextarc;//指向下一条弧
};

class Graph {
public:
	ArcNode * adjList[MAX_VERTEX_NUM];//指向依附于该顶点的(第一条)弧
	int vexnum, arcnum;//当前顶点、弧数
	int GraphKind;//0：无向     1：有向
	int visited[MAX_VERTEX_NUM];

	void CreateGraph();
	void DFSTraverse();
	void DFS(int);
	void BFSTraverse();
	int FirstAdjVex(int);//求图中某一顶点的第一个邻接顶点
	int NextAdjVex(int, int);//求某一顶点的下一个邻接顶点
};

