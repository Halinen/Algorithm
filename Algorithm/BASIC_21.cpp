#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
string ans;
int n = 0;
//思路：dfs算出An
//由样例结果分析：
//分割要打印的结果：前面的一堆括号 +“Ai+k)”,最后一个无')'
//感谢@wlw大佬提供的递归解法
void dfs(int n, int t) {
	if (n == t + 1)	return;
	ans = ans + "sin(";
	ans += to_string(n);
	if (t > n) {
		if (n % 2 == 1)//奇数
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