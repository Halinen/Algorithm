#include<iostream>
#include<stdlib.h>
#include"Prim.h"
using namespace std;
int main() {
	int st;
	AdjMatrix *G, *p;
	p = new AdjMatrix;
	
	G = p->creat();
	//������������Ӧ���ڽӾ���
	G->display();
	//���빹����С�����������
	cin >> st;
	G->prim(st);
	delete(p);
	system("pause");
	return 0;
}