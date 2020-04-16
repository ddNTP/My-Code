#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
unordered_map <char, bool>m;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		m[s[i]] = true;
	for (int i = 0; i < s.size() - n + 1; i++) {
		if (m[s[i]]) {
			int j;
			for (j = i; j < i + n - 1; j++) {
				if (s[j] == s[j + 1])continue;
				else {
					m[s[i]] = false;
					break;
				}
			}
			if (j == i + n - 1)i = j;
		}
	}
	if(!m[s[s.size()-n]])
		for (int i = s.size() - n + 1; i < s.size(); i++)
			m[s[i]] = false;
	vector<char>ans;
	for (int i = 0; i < s.size(); i++) {
		if (m[s[i]]) {
			if (find(ans.begin(), ans.end(), s[i]) == ans.end()) {
				ans.push_back(s[i]);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
	cout << endl;
	for (int i = 0; i < s.size(); i++) {
		if (!m[s[i]])cout << s[i];
		else {
			cout << s[i];
			i = i + n - 1;
		}
	}
	system("pause");
	return 0;
}