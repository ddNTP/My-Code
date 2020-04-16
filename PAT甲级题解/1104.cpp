#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	double ans = 0;
	double t;
	for (long long i = 0; i < n; i++) {//要用long long不然测试点3.4会错误；
		cin >> t;
		ans += (i + 1)*(n - i)*t;
	}
	printf("%.2f", ans);
	return 0;
}