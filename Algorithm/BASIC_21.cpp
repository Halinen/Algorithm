#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
string ans;
int n = 0;
//˼·��dfs���An
//���������������
//�ָ�Ҫ��ӡ�Ľ����ǰ���һ������ +��Ai+k)��,���һ����')'
//��л@wlw�����ṩ�ĵݹ�ⷨ
void dfs(int n, int t) {
	if (n == t + 1)	return;
	ans = ans + "sin(";
	ans += to_string(n);
	if (t > n) {
		if (n % 2 == 1)//����
			ans += '-';
		else ans += '+';
	}
	dfs(n + 1, t);
	ans += ')';
}
int main() {
	cin >> n;
	string res;
	for (int i = 0; i < n-1; i++) {
		res = res + '(';
	}
	for (int i = 1, k = n; i <= n; i++, k--) {
		dfs(1, i);
		res += ans + '+' + to_string(k);
		if (k != 1) {
			res += ')';
		}
		ans = "";
	}
	cout << res;
	system("pause");

}