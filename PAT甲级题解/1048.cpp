#include<iostream>
using namespace std;
int a[1010];
int main() {
	int n, m;
	cin >> n >> m;
	int b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		a[b]++;
	}
	for (int i = 1; i < m; i++) {
		int j = m - i;
		if (i != j && a[i] != 0 && a[j] != 0) {
			printf("%d %d", i, j);
			return 0;
		}
		if (i == j && a[i] >= 2) {
			printf("%d %d", i, i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}