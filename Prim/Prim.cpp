#include "Prim.h"
#include<iostream>

using namespace std;
int AdjMatrix::Locate(int v)//求顶点位置
{
	int j = -1;
	for (int i = 0; i < this->vexnum; i++) {
		if (this->vexs[i] == v) {
			j = i;
			break;
		}
	}
	return j;
}

AdjMatrix * AdjMatrix::creat()
{
	int v1, v2, w, j;
	//输入顶点数
	cin >> this->vexnum;
	if (this->vexnum <= 1) {
		cout << "最小生成树不存在" << endl;
		return this;
	}
	else {
		//输入边数
		cin >> this->arcnum;
		//初始化邻接矩阵
		for (int i = 0; i < this->vexnum; i++) {
			for (j = 0; j < this->vexnum; j++) {
				if (i == j) {
					this->arcs[i][j].adj = 0;
				}
				else {
					this->arcs[i][j].adj = INT_MAX;
				}
			}
		}
		//输入顶点编号序列
		for (int i = 0; i < this->vexnum; i++) {
			cin >> this->vexs[i];
		}
		//输入每条边的两个顶点及权值
		for (int i = 0; i < this->arcnum; i++) {
			cin >> v1 >> v2 >> w;
			i = Locate(v1);//次顶点编号对应位置
			j = Locate(v2);
			this->arcs[i][j].adj = w;
			this->arcs[j][i].adj = w;
		}
	}
	return this;
}

//找到close中权值最小的边
int AdjMatrix::minium(Node close[])
{
	int i, min = INT_MAX, t;
	for (i = 0; i < this->vexnum; i++) {
		if (this->close[i].lowcost < min&&this->close[i].lowcost != 0) {
			min = close[i].lowcost;
			t = i;
		}
	}
	return t;//返回权值最小的边在辅助数组中的位置
}

void AdjMatrix::prim(int u)
{
	int n = 0, k0, u0, v0, s = 0;
	AdjMatrix *p = new AdjMatrix;
	int k = this->Locate(u);//K为顶点u位置
	p->vexs[n++] = u;//最小生成树从顶点u出发
	this->close[k].lowcost = 0;//初始化辅助数组

	for (int i = 0; i < this->vexnum; i++) {
		if (i != k) {
			close[i].adjvex = u;
			close[i].lowcost = this->arcs[k][i].adj;
		}
		for (int j = 1; j <= this->vexnum; j++) {
			k0 = this->minium(this->close);//权值最小的边在辅助数组中的位置
			u0 = this->close[k0].adjvex;
			v0 = this->vexs[k0];
			p->vexs[n++] = v0;//放入最小生成树
			s += this->close[k0].lowcost;
			printf("    <%d->%d>\t%d\n", u0, v0, close[k0].lowcost);
			close[k0].lowcost = 0;//放入过了更新权值
			for (int i = 0; i < this->vexnum; i++) {
				if (this->arcs[k0][i].adj < this->close[i].lowcost) {
					//从k0出发的边的权值和之前的表中的权值进行比较
					this->close[i].lowcost = this->arcs[k0][i].adj;
					close[i].adjvex = v0;
				}
			}
			//最小生成树顶点序列
			for (int i = 0; i < this->vexnum; i++) {
				cout << p->vexs[i] << "   ";
			}
			cout << endl << "权值和" << s << endl;
		}
	}

	

	

}

void AdjMatrix::display()
{
	int i, j;
	for (i = 0; i < this->vexnum; i++) {
		cout << this->vexs[i] << " ";//输出顶点编号
	}
	for (i = 0; i < this->vexnum; i++) {
		cout << this->vexs[i] << "    |";
		for (j = 0; j < this->vexnum; j++) {
			if (this->arcs[i][j].adj = INT_MAX) {
				cout << '\t' << "∞";
			}
			else{
				cout << '\t' << this->arcs[i][j].adj;
			}
		}
		cout << endl;
	}
	cout << endl;

}
