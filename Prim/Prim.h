#pragma once
#define MAX 20
//�� Ȩ
//�� ��� Ȩ
//����ͼ ���㼯�� �߼��� �������� ������������
class ArcNode {
public:
	int adj;//��Ȩ
};

class Node {
public:
	int adjvex;//������
	int lowcost;//����Ȩֵ
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
