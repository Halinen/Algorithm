#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;
//�ҿޣ���������С�����ķ����� (((�Һ��Լ����˻����ºϲ�����555
//�����ȰѾ�������궼��ɴ����µ����ϵ�˳�� 
//���ж��Ƿ��غϢں���������ȡ�м������Ĳ�ֵΪ�غ������һ���߳��ȣ�����������ȡ...��over~
//һ��������ѧ̫�����ˣ�����
int main() {
	double x1, y1, x2, y2, x3, y3, x4, y4, t;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	if (x1 > x2)	swap(x1, x2);
	if (y1 > y2)	swap(y1, y2);
	if (x3 > x4)	swap(x3, x4);
	if (y3 > y4)	swap(y3, y4);
	if ((x1 < x3&&x2 < x3) || (y1 < y3&&y2 < y3) || (y3 < y1&&y4 < y1) || (x3 < x1&&x4 < x1)) {
		cout << 0.00;
		return 0;//return 0�ͷ��ز���ϵͳ��  ���治��Ҫelse
	}
	double a[4] = { x1,x2,x3,x4 };
	double b[4] = { y1,y2,y3,y4 };
	sort(a, a + 4);
	sort(b, b + 4);
	double ans = (a[2] - a[1])*(b[2] - b[1]);
	printf("%.2lf", ans);
	system("pause");
	return 0;
}