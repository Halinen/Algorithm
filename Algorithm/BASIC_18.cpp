#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;
//我哭！！！附上小柳柳的分析！ (((我害自己画了画推下合不合理555
//〇！先把矩阵的坐标都变成从左下到右上的顺序 
//①判断是否不重合②横坐标排序，取中间两个的差值为重合面积的一条边长度；纵坐标排序，取...→over~
//一定是我数学太垃圾了（掩面
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
		return 0;//return 0就返回操作系统了  后面不需要else
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