#include"Graph.h"
#include<queue>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	Graph G;
	cin >> G.GraphKind >> G.vexnum >> G.arcnum;
	G.CreateGraph();
	G.DFSTraverse();
	G.BFSTraverse();
	system("pause");
	return 0;
}
//1 5 12
//1 4
//1 2
//2 5
//2 3
//2 1
//3 5
//3 4
//3 2
//4 3
//4 1
//5 3
//5 2