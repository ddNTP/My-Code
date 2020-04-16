#include<iostream>
using namespace std;
int n;
unsigned long long  res;
int dfs(unsigned long long x, int t) {
	if (x%n == 0) {
		res = x;
		return 1;
	}
	if (t == 19)return 0;
	if (dfs(x * 10, t + 1))return 1;
	if (dfs(x * 10 + 1, t + 1))return 1;
}
int main() {

	cin >> n;
	while (n != 0) {
		dfs(1, 0);
		cout << res << endl;
		cin >> n;
	}
	system("pause");
	return 0;
}