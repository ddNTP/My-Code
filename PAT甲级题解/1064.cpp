#include<iostream>
#include<algorithm>
using namespace std;
int a[10000], b[10000];
int n;
int cnt = 0;
void level(int root) {
	if (root > n)return;
	level(root * 2);
	b[root] = a[cnt++];
	level(root * 2 + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	level(1);
	for (int i = 1; i <= n; i++) {
		printf("%d", b[i]);
		if (i != n)printf(" ");
	}
	system("pause");
	return 0;
}