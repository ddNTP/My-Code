#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n1, n2;
	cin >> n1;
	int t;
	vector<int>a;
	for (int i = 0; i < n1; i++) {
		cin >> t;
		a.push_back(t);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	printf("%d", a[(a.size() - 1) / 2]);
	return 0;
}