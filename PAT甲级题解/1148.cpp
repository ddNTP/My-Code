#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<int>a(n + 1);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int cnt1 = 0, cnt2 = 0;
			for (int k = 1; k <= n; k++) {
				if (k != i && k != j)
					a[k] = 1;
				else a[k] = -1;
			}
			for (int k = 1; k <= n; k++) {
				if (v[k] * a[abs(v[k])]<0) {
					if(k!=i&&k!=j)
						cnt2++;
					else cnt1++;
				}
			}
			if (cnt1 == 1 && cnt2 == 1) {
				printf("%d %d", i, j);
				system("pause");
				return 0;
			}
		}
	}
	printf("No Solution");
	system("pause");
	return 0;
}