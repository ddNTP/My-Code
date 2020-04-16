#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>a;
	int b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		int j = lower_bound(a.begin() + i + 1, a.end(), m - a[i]) - a.begin();
		if (j!=n&&a[j] == m - a[i]) {
			printf("%d %d", a[i], a[j]);
			system("pause");
			return 0;
		}
	}
	printf("No Solution");
	system("pause");
	return 0;
}