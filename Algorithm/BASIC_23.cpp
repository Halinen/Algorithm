#include<iostream>
#include<stdlib.h>
using namespace std;
//Ӧ�ÿ��У���������оƬ�����Ĳ��ԣ�
//����Ǻ� �Ǵ��ڰ������Զ�Ϊ1 ��Ϊ���������Ǻõ�оƬ�����Ϊ��
int main() {
	int n, a[20][20], cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 1 && i != j)
				cnt++;
		}
		if (cnt >= n / 2)
			cout << i+1 << " ";
	}
	system("pause");
	return 0;
}