#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b) {
	return a > b;
}
int main() {
	int n, a[1001], m, l, r, k, b[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> k;
		for (int j = 0; j < n; j++) {
			b[j] = a[j];
		}
		sort(b + l - 1, b + r,cmp);
		cout << b[l + k - 2] << endl;
	}
	system("pause");


	return 0;
}