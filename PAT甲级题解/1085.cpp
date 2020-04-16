#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int main() {
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int cnt=0;
	for (int i = 0; i <n; i++) {
		int j = upper_bound(a + i, a + n, (long long)p*a[i]) - a;
		cnt = max(cnt, j - i);
	}
	printf("%d", cnt);
	system("pause");
	return 0;
}