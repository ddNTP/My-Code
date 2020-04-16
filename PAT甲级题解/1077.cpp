#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf_s("%d\n", &n);
	string s,ans;
	getline(cin, ans);
	int m = ans.length();
	reverse(ans.begin(), ans.end());
	for (int i = 1; i < n; i++) {
		getline(cin, s);
		reverse(s.begin(), s.end());
		int t = s.length();
		if (t >= m) 
			for (int j = m; j >= 0; j--) {
				if (j == 0) {
					m = 0;
					break;
				}
				if (s.substr(0, j) == ans.substr(0, j)) {
					m = j;
					break;
				}
			}
		else 
			for (int j = t; j >= 0; j--) {
				if (j == 0) {
					m = 0;
					break;
				}
				if (s.substr(0, j) == ans.substr(0, j)) {
					m = j;
					break;
				}
			}		
	}
	string ans1;
	if (m == 0) {
		printf("nai");
		system("pause");
		return 0;
	}
	else {
		ans1 = ans.substr(0, m);
		reverse(ans1.begin(), ans1.end());
		cout << ans1;
	}
	system("pause");
	return 0;
}