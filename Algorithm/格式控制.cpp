#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
const int N = 1000001;
int F[N] = { 0 };//����ջ�����������������̬������
int main() {
	//��long long��Χ 1e18  int��Χ2147483648 
	//long long�ĸ�ʽ���ƣ�(��)I64d lld
	long long a = 1e18;
	printf("%lld\n", a);

	//����Բ���������ѧ��ʽ����PI: atan(1.0) * 4
	int r;
	cin >> r;
	double PI = atan(1.0) * 4;
	double s = PI * r * r;
	printf("%.7lf\n", s);

	//��Fibonacci���еĵ��ƹ�ʽΪ��Fn=Fn-1+Fn-2������F1=F2=1��
	//��n�Ƚϴ�ʱ��FnҲ�ǳ�������������֪����Fn����10007�������Ƕ��١�
	//ֱ�Ӽ������������������ԭ����ȡ���
	F[1] = 1; F[2] = 1;
	for (int i = 3; i <= r; i++) {
		F[i] = (F[i - 1] + F[i - 2]) % 10007;
	}
	cout << F[r] << endl;
	

	//����ĸͼ�� �ҹ���  Ҫ�Ծ����������abs��ó��Ķ������У�
	int g, h;
	cin >> g >> h;
	for (int j = 0; j < g; j++) {
		for (int i = 0; i < h; i++) {
			cout << char('A' + abs(i - j));
		}
		cout << endl;
	}

	//��������� ÿ�е�һ�������Խ���Ԫ��Ϊ1 ����ͨ��a[i][j] = a[i - 1][j - 1] + a[i - 1][j]�ó� �����ά����



	system("pause");
	return 0;
}