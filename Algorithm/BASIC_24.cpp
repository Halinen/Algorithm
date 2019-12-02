#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int main() {
	int v1, v2, t, s, l, h = 0, temp, p = 0;//h p兔子花的总时间 路程
	cin >> v1 >> v2 >> t >> s >> l;
	temp = ceil(t / (v1 - v2));
	p += temp * v1;
	h += temp;
	while (p < l) {
		h += s;
		temp = ceil((s*v2 + t) / v1);
		
		if (p + temp * v1 >= l) {
			h += (ceil)((l - p) / v1);
			break;
		}
		p += temp * v1;
		h += temp;
	}
	if (ceil(l / v2) > h)
		cout << 'T' << endl << ceil(l / v2);
	else if (ceil(l / v2) < h)
		cout << 'R' << endl << h;
	else
		cout << 'D' << endl << h;
	system("pause");
	return 0;
}