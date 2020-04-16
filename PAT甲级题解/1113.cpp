#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += v[i];
	if (n % 2 == 1) {
		printf("1 ");
		int n1 = n / 2;
		if (v[n1] >= 0&&sum>=0) {
			ll total = 0;
			for (int i = 0; i < n1; i++)
				total -= v[i];
			for (int i = n1; i < n; i++)
				total += v[i];
			cout << abs(total);
		}
		else if (v[n1] >= 0 && sum < 0) {
			ll total = 0;
			for (int i = 0; i < n1 + 1; i++)
				total -= v[i];
			for (int i = n1 + 1; i < n; i++)
				total += v[i];
			cout << abs(total);
		}
		else if (v[n1] < 0 && sum >= 0) {
			ll total = 0;
			for (int i = 0; i < n1 + 1; i++)
				total -= v[i];
			for (int i = n1 + 1; i < n; i++)
				total += v[i];
			cout << abs(total);
		}
		else {
			ll total = 0;
			for (int i = 0; i < n1; i++)
				total -= v[i];
			for (int i = n1; i < n; i++)
				total += v[i];
			cout << abs(total);
		}
	}
	else {
		cout << "0 ";
		ll total = 0;
		int n1 = n / 2;
		for (int i = 0; i < n1; i++)
			total -= v[i];
		for (int i = n1; i < n; i++)
			total += v[i];
		cout << abs(total);
	}
	system("pause");
	return 0;
}