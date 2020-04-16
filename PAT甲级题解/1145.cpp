#include<iostream>
#include<math.h>
#include<vector>
#include<map>
using namespace std;
bool isprime(int n) {
	if (n < 2)return false;
	int q = sqrt(n);
	for (int i = 2; i <= q; i++)
		if (n%i == 0)return false;
	return true;
}
int minprime(int n) {
	while (!isprime(n))n++;
	return n;
}
int main() {
	int msize, n, m;
	cin >> msize >> n >> m;
	int size = minprime(msize);
	vector<int>v(size);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int x = t % size;
		int j = 1;
		while (v[x] != 0 && j <= size) {
			x = t + j * j;
			x = x % size;
			j++;
		}
		if (j == size + 1) {
			printf("%d cannot be inserted.\n", t);
			continue;
		}
		v[x] = t;
	}
	int total = 0;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		int x = t % size;
		int j = 1;
		while (v[x] != 0 && j <= size && v[x] != t) {
			x = (t + j * j) % size;
			j++;
		}
		total += j;
	}
	double ans = total * 1.0 / m;
	int ans1 = ans * 10 + 0.5;
	ans = ans1*1.0 / 10;
	printf("%.1f", ans);
	system("pause");
	return 0;
}