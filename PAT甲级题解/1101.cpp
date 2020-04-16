#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int lmax[100010],rmin[100010];
int a[100010];
int main() {
	int n;
	cin >> n;
	int m = 0;
	int t;
	lmax[0] = 0;
	rmin[n - 1] =INT_MAX ;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[i] = t;
		if (m < t)m = t;
		lmax[i + 1] = m;
	}
	m = INT_MAX;
	for (int i = n - 1; i > 0; i--) {
		if (m > a[i])m = a[i];
		rmin[i - 1] = m;
	}
	vector<int>v;
	for (int i = 0; i < n; i++) 
		if (a[i] > lmax[i] && a[i] < rmin[i])v.push_back(a[i]);
	cout << v.size() << endl;
	if (v.size() == 0)cout << endl;
	for (int i = 0; i < v.size(); i++) {
		if (i != 0)cout << " ";
		cout << v[i];
	}
	system("pause");
	return 0;
}