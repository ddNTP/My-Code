#include<iostream>
#include<map>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, bool>m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		m[t] = true;
	}
	int i = 1;
	while (m[i])i++;
	cout << i;
	return 0;
}