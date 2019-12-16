#include<iostream>
#include<stdlib.h>
#include"Prim.h"
using namespace std;
int main() {
	int st;
	AdjMatrix *G, *p;
	p = new AdjMatrix;
	
	G = p->creat();
	//输入无向网对应的邻接矩阵
	G->display();
	//输入构造最小生成树的起点
	cin >> st;
	G->prim(st);
	delete(p);
	system("pause");
	return 0;
}