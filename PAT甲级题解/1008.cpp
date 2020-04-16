#include<iostream>
using namespace std;
int main() {
	int a[100010];
	int n;
	cin >> n;
	a[0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int t;
		t = a[i] - a[i - 1];
		if (t > 0)ans += 6 * t;
		else ans += -4 * t;
		ans += 5;
	}
	cout << ans;
	system("pause");
	return 0;
}