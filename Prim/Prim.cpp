#include "Prim.h"
#include<iostream>

using namespace std;
int AdjMatrix::Locate(int v)//�󶥵�λ��
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
	//���붥����
	cin >> this->vexnum;
	if (this->vexnum <= 1) {
		cout << "��С������������" << endl;
		return this;
	}
	else {
		//�������
		cin >> this->arcnum;
		//��ʼ���ڽӾ���
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
		//���붥��������
		for (int i = 0; i < this->vexnum; i++) {
			cin >> this->vexs[i];
		}
		//����ÿ���ߵ��������㼰Ȩֵ
		for (int i = 0; i < this->arcnum; i++) {
			cin >> v1 >> v2 >> w;
			i = Locate(v1);//�ζ����Ŷ�Ӧλ��
			j = Locate(v2);
			this->arcs[i][j].adj = w;
			this->arcs[j][i].adj = w;
		}
	}
	return this;
}

//�ҵ�close��Ȩֵ��С�ı�
int AdjMatrix::minium(Node close[])
{
	int i, min = INT_MAX, t;
	for (i = 0; i < this->vexnum; i++) {
		if (this->close[i].lowcost < min&&this->close[i].lowcost != 0) {
			min = close[i].lowcost;
			t = i;
		}
	}
	return t;//����Ȩֵ��С�ı��ڸ��������е�λ��
}

void AdjMatrix::prim(int u)
{
	int n = 0, k0, u0, v0, s = 0;
	AdjMatrix *p = new AdjMatrix;
	int k = this->Locate(u);//KΪ����uλ��
	p->vexs[n++] = u;//��С�������Ӷ���u����
	this->close[k].lowcost = 0;//��ʼ����������

	for (int i = 0; i < this->vexnum; i++) {
		if (i != k) {
			close[i].adjvex = u;
			close[i].lowcost = this->arcs[k][i].adj;
		}
		for (int j = 1; j <= this->vexnum; j++) {
			k0 = this->minium(this->close);//Ȩֵ��С�ı��ڸ��������е�λ��
			u0 = this->close[k0].adjvex;
			v0 = this->vexs[k0];
			p->vexs[n++] = v0;//������С������
			s += this->close[k0].lowcost;
			printf("    <%d->%d>\t%d\n", u0, v0, close[k0].lowcost);
			close[k0].lowcost = 0;//������˸���Ȩֵ
			for (int i = 0; i < this->vexnum; i++) {
				if (this->arcs[k0][i].adj < this->close[i].lowcost) {
					//��k0�����ıߵ�Ȩֵ��֮ǰ�ı��е�Ȩֵ���бȽ�
					this->close[i].lowcost = this->arcs[k0][i].adj;
					close[i].adjvex = v0;
				}
			}
			//��С��������������
			for (int i = 0; i < this->vexnum; i++) {
				cout << p->vexs[i] << "   ";
			}
			cout << endl << "Ȩֵ��" << s << endl;
		}
	}

	

	

}

void AdjMatrix::display()
{
	int i, j;
	for (i = 0; i < this->vexnum; i++) {
		cout << this->vexs[i] << " ";//���������
	}
	for (i = 0; i < this->vexnum; i++) {
		cout << this->vexs[i] << "    |";
		for (j = 0; j < this->vexnum; j++) {
			if (this->arcs[i][j].adj = INT_MAX) {
				cout << '\t' << "��";
			}
			else{
				cout << '\t' << this->arcs[i][j].adj;
			}
		}
		cout << endl;
	}
	cout << endl;

}
