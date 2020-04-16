#include<iostream>
using namespace std;
int main() {
	int m, n, t;
	float num;
	float p[1001] = { 0 };
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d%f", &t, &num);
		p[t] += num;
	}
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d%f", &t, &num);
		p[t] += num;
	}
	int count = 0;
	for (int i = 0; i<1001; i++) {
		if (p[i] != 0) count++;
	}
	printf("%d", count);
	for (int i = 1000; i >= 0; i--) {
		if (p[i] != 0) printf(" %d %.1f", i, p[i]);
	}
	system("pause");
	return 0;
}