#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	vector <int> a;
	while (true) {
		a.push_back(n % b);
		n /= b;
		if (n == 0)break;
	}
	bool flag = true;
	for (int i = 0; i < int(a.size() / 2); i++)
		if (a[i] != a[a.size() - 1 - i])flag = false;
	if (flag)printf("Yes\n");
	else printf("No\n");
	for (int i = a.size() - 1; i > 0; i--) printf("%d ", a[i]);
	printf("%d", a[0]);
	return 0;
}