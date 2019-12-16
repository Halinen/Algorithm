#pragma once
#define MAX 20
//边 权
//点 编号 权
//无向图 顶点集合 边集合 辅助矩阵 顶点数、边数
class ArcNode {
public:
	int adj;//边权
};

class Node {
public:
	int adjvex;//顶点编号
	int lowcost;//顶点权值
};

class AdjMatrix {
public:
	int vexs[MAX];
	int vexnum, arcnum;
	ArcNode arcs[MAX][MAX];
	Node close[MAX];

	int Locate(int v);
	AdjMatrix *creat();
	int minium(Node close[]);
	void prim(int u);
	void display();
};
