#pragma once
#include<queue>
#define MAX_VERTEX_NUM 20  //��󶥵���

class ArcNode {
public:
	int adjvex;//�û�ָ��Ķ���λ��
	ArcNode *nextarc;//ָ����һ����
};

class Graph {
public:
	ArcNode * adjList[MAX_VERTEX_NUM];//ָ�������ڸö����(��һ��)��
	int vexnum, arcnum;//��ǰ���㡢����
	int GraphKind;//0������     1������
	int visited[MAX_VERTEX_NUM];

	void CreateGraph();
	void DFSTraverse();
	void DFS(int);
	void BFSTraverse();
	int FirstAdjVex(int);//��ͼ��ĳһ����ĵ�һ���ڽӶ���
	int NextAdjVex(int, int);//��ĳһ�������һ���ڽӶ���
};

