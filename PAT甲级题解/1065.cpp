#include<iostream>
using namespace std;
int main() {
	long long a, b, c;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		long long res = a + b;  //a+b必须存到变量中再讨论溢出问题
		if (a > 0 && b > 0 && res <= -2)printf("Case #%d: true\n", i + 1);
		else if (a < 0 && b < 0 && res >= 0)printf("Case #%d: false\n", i + 1);
		else {
			if (res > c)printf("Case #%d: true\n", i + 1);
			else printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}