#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str[10100];
bool cmp1(string a, string b) {
	return a + b < b + a;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> str[i];
	sort(str, str + n, cmp1);
	string s="";
	for (int i = 0; i < n; i++)
		s += str[i];
	while (s.length() != 0 && s[0] == '0') {
		s.erase(s.begin());
	}
	if (s.length() == 0) {
		cout << 0; return 0;
	}
	cout << s;
	system("pause");
	return 0;
}