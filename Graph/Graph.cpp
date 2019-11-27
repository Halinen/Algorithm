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
		this->adjList[i] = NULL;//�Ż��Ľ���
	}
	//������ߵ��������㣨��β����ͷ
	for (i = 1; i <= this->arcnum; i++) {
		cin >> start >> end;
		s = new ArcNode();//newһ�������
		s->nextarc = this->adjList[start];//��һ������...ͷ��
		s->adjvex = end;//�û�ָ��Ķ���λ��
		this->adjList[start] = s;//�Ż������ڻ�β��Ӧ��λ��
		if (this->GraphKind == 0) {//���������ͼ����˫��ģ���ͷ��β�����б�����������
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
	//dfs��������
	memset(this->visited, 0, sizeof(visited));
	cout << "DFS�����";
	for (i = 1; i <= this->vexnum; i++) {
		if (!this->visited[i])
			DFS(i);
	}
	cout << endl;
}

void Graph::DFS(int i)//�ӵ�i����������ݹ�dfsͼG
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
	//bfs��������
	memset(visited, 0, sizeof(visited));
	cout << "BFS�����";
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

int Graph::FirstAdjVex(int v)//��ͼG���ҵ�v���������һ���ڽӶ���
{
	if (!this->adjList[v])
		return 0;
	else
		return(this->adjList[v]->adjvex);
}

int Graph::NextAdjVex(int v, int u)//�ҵ���v������������u����һ���ڽӶ���
{
	ArcNode *p;
	p = this->adjList[v];
	while (p->adjvex != u) {//�ҵ�u
		p = p->nextarc;
	}
	if (p->nextarc == NULL) {
		return 0;//���У���������һ������
	}
	else {
		return p->nextarc->adjvex;//p����һ�����Ķ���λ��
	}
	return 0;
}
