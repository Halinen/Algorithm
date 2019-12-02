#include<iostream>
#include<stdlib.h>
using namespace std;
//应该看列！列是其他芯片对它的测试！
//如果是好 那大于半数测试都为1 因为超过半数是好的芯片（结果为好
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