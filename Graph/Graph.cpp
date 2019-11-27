#include "Graph.h"
#include<queue>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void Graph::CreateGraph()
{
	int i, start, end;
	ArcNode *s;
	for (i = 1; i <= this->vexnum; i++) {
		this->adjList[i] = NULL;//放弧的结点表
	}
	//输入各边的两个顶点（弧尾、弧头
	for (i = 1; i <= this->arcnum; i++) {
		cin >> start >> end;
		s = new ArcNode();//new一个弧结点
		s->nextarc = this->adjList[start];//下一条弧是...头插
		s->adjvex = end;//该弧指向的顶点位置
		this->adjList[start] = s;//放弧，放在弧尾对应的位置
		if (this->GraphKind == 0) {//如果是无向图，（双向的，弧头弧尾顶点列表都该有这条弧
			s = new ArcNode();
			s->nextarc = this->adjList[end];
			s->adjvex = start;
			this->adjList[end] = s;
		}
	}
}

void Graph::DFSTraverse()
{
	int i;
	//dfs遍历序列
	memset(this->visited, 0, sizeof(visited));
	cout << "DFS结果是";
	for (i = 1; i <= this->vexnum; i++) {
		if (!this->visited[i])
			DFS(i);
	}
	cout << endl;
}

void Graph::DFS(int i)//从第i个顶点出发递归dfs图G
{
	int w;
	this->visited[i] = 1;
	cout << '-' << '>' << i;
	for (w = FirstAdjVex(i); w; w = NextAdjVex(i, w)) {
		if (!this->visited[w])
			DFS(w);
	}
}

void Graph::BFSTraverse()
{
	int i, u, w;
	queue<int>q;
	//bfs遍历序列
	memset(visited, 0, sizeof(visited));
	cout << "BFS结果是";
	for (i = 1; i <= this->vexnum; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			cout << '-' << '>' << i;
			q.push(i);
			while (!q.empty()) {
				u = q.front();
				q.pop();
				for (w = FirstAdjVex(u); w; w = NextAdjVex(u, w)) {
					if (!visited[w]) {
						visited[w] = 1;
						cout << '-' << '>' << w;
						q.push(w);
					}
				}
			} 
		}
	}
}

int Graph::FirstAdjVex(int v)//在图G中找第v个顶点的下一个邻接顶点
{
	if (!this->adjList[v])
		return 0;
	else
		return(this->adjList[v]->adjvex);
}

int Graph::NextAdjVex(int v, int u)//找到第v个顶点的相对于u的下一个邻接顶点
{
	ArcNode *p;
	p = this->adjList[v];
	while (p->adjvex != u) {//找到u
		p = p->nextarc;
	}
	if (p->nextarc == NULL) {
		return 0;//特判，如果是最后一个顶点
	}
	else {
		return p->nextarc->adjvex;//p的下一条弧的顶点位置
	}
	return 0;
}
