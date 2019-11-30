#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
string b[10] = { "ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu " };
string func(string t) {
	string ans;
	int lent = t.length();
	if (lent >= 4) {
		ans += b[t[0] - '0'];
		ans += "qian ";
	}
	if (lent >= 3) {
		if (t[lent - 3] != '0') {//从右数第三个数
			ans += b[t[lent - 3] - '0'];
			ans += "bai ";
		}
	}
	if (lent >= 2) {
		if (t[lent - 2] == '1') {//从右数第二个数
			if (lent != 2) {
				ans += "yi shi ";
			}
			else {
				ans += "shi ";
			}
		}
		if (t[lent - 2] != '0'&&t[lent - 2] != '1') {//0不读 1上面特判过了
			ans += b[t[lent - 2] - '0'];
			ans += "shi ";
		}
	}
	if (lent >= 1) {
		if (t[lent - 1] != '0') {
			ans += b[t[lent - 1] - '0'];
		}
	}
	return ans;
}
int main() {//substr起始位置，字符数目
	string s, sub;
	cin >> s;
	int len = s.length();
	if (len == 10) {//十亿级
		sub = s.substr(0, 2);
		cout << func(sub) << "yi";
	}
	if (len == 9) {//亿级
		sub = s.substr(0, 1);
		cout << func(sub) << "yi";
	}
	sub = " ";
	int flag = 0;
	if (len >= 5) {//如果大于一万
		for (int i = len - 8; i < len - 4; i++) {//前面几位
			if (i < 0) continue;//去除越界的，只看实际大于等于万位的部分
			if (flag == 0 && s[i] == '0') {//最前面位等于零不读出来
				continue;
			}
			sub += s[i];
			flag = 1;//前面位有非零了flag置1
		}
		if (flag == 1) {//有非零了 放func里分割读出来再加个wan
			cout << func(sub) << "wan";
		}
		flag = 0;//flag复位
		sub = " ";
		for (int i = len - 4; i < len; i++) {//看后面四位
			if (flag == 0 && s[i] == 0) {//最前面位等于零不读出来
				continue;
			}
			if ((i == len - 1 && s[i - 1] == '0') || (i == len - 2 && s[i - 1] == '0') || (i == len - 3) && s[i - 1] == '0') {
				cout << "ling";//如果i是个位且十位为0;...;如果i是百位且千位为0
			}
			sub += s[i];
			flag = 1;//有非零元素了
		}
	}
	if (len <= 4) {//千位及以下
		sub = s;
		flag = 1;
	}
	if (flag == 1) {
		cout << func(sub);
	}
	system("pause");
	return 0;
}