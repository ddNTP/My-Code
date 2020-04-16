#include<iostream>
#include<cctype>
#include<map>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	map<string, int>m;
	for (int i = 0; i < s.size(); i++) {
		int j = i;
		for (; j <= s.size(); j++) {
			if (j == s.size())break;
			if (isalpha(s[j]))s[j] = tolower(s[j]);
			if (!isalnum(s[j]))break;
		}
		if (j > i) {
			string a = s.substr(i, j - i);
			if (m.find(a) == m.end())m[a] = 1;
			else m[a]++;
		}
		i = j;
	}
	int max = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second > max)max = it->second;
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second == max) {
			cout << it->first << " " << max;
			break;
		}
	system("pause");
	return 0;
}