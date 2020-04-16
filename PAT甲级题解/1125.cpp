#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	double ans = v[0];
	for (int i = 1; i < v.size(); i++) {
		ans = (ans + v[i]) / 2;
	}
	if (abs(ans - int(ans)-0.5)<1e-7)printf("%d", min(int(ans) + 1,v[v.size()-1]));
	else printf("%d", min(int(ans), v[v.size() - 1]));
	system("pause");
	return 0;
}