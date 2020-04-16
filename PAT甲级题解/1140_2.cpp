#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int n;
	cin >> s >> n;
	for (int i = 0; i < n - 1; i++) {
		string t = "";
		for (int j = 0; j < s.size();) {
			int cnt = 1;
			while (j + 1 < s.size() && s[j + 1] == s[j]) {
				j++;
				cnt++;
			}
			t = t + s[j] + to_string(cnt);
			j++;
		}
		s = t;
	}
	cout << s;
	system("pause");
	return 0;
}