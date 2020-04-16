#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int main() {
	int m, n;
	cin >> m >> n;
	map<ll, int>a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			if (a.find(t) == a.end())a[t] = 1;
			else a[t]++;
		}
	}
	int max=0;
	for (auto it = a.begin(); it != a.end(); it++) {
		if (it->second > max)max = it->second;
	}
	for(auto it =a.begin();it!=a.end();it++)
		if (it->second == max) {
			cout << it->first;
			break;
		}
	system("pause");
	return 0;
}