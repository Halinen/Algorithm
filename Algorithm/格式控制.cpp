#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
const int N = 1000001;
int F[N] = { 0 };//放在栈区溢出，所以移至静态数据区
int main() {
	//①long long范围 1e18  int范围2147483648 
	//long long的格式控制：(爱)I64d lld
	long long a = 1e18;
	printf("%lld\n", a);

	//②求圆面积。用数学公式计算PI: atan(1.0) * 4
	int r;
	cin >> r;
	double PI = atan(1.0) * 4;
	double s = PI * r * r;
	printf("%.7lf\n", s);

	//③Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。
	//当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
	//直接计算余数往往比先算出原数再取余简单
	F[1] = 1; F[2] = 1;
	for (int i = 3; i <= r; i++) {
		F[i] = (F[i - 1] + F[i - 2]) % 10007;
	}
	cout << F[r] << endl;
	

	//④字母图形 找规律  要对矩阵行列相减abs后得出的东西敏感！
	int g, h;
	cin >> g >> h;
	for (int j = 0; j < g; j++) {
		for (int i = 0; i < h; i++) {
			cout << char('A' + abs(i - j));
		}
		cout << endl;
	}

	//⑤杨辉三角 每行第一个和主对角线元素为1 其余通过a[i][j] = a[i - 1][j - 1] + a[i - 1][j]得出 输出二维数组



	system("pause");
	return 0;
}