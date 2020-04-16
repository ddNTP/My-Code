#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int t = 0;
	for (int i = 0; i < b.size(); i++) {
		int x = a[i] - '0' + b[i] - '0' + t;
		t = x / 10;
		a[i] = x % 10 + '0';
	}
	for (int i = b.size(); i < a.size(); i++) {
		int x = a[i] - '0' + t;
		t = x / 10;
		a[i] = x % 10 + '0';
	}
	if (t == 1)a = a + '1';
	reverse(a.begin(), a.end());
	return a;
}

int main() {
	string s;
	cin >> s;
	int i = 0;;
	for (; i < 10; i++) {
		bool flag = true;
		for (int j = 0; j < s.size() / 2; j++) {
			if (s[j] != s[s.size() - 1 - j]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			string s1 = s;
			reverse(s1.begin(),s1.end());
			int j = 0;
			while (s1[j] == '0')j++;
			j = min(int(s1.size() - 1), j);
			s1 = s1.substr(j, s1.size() - j);
			j = 0;
			while (s[j] == '0')j++;
			j = min(int(s.size() - 1), j);
			s = s.substr(j, s.size() - j);
			
			cout << s << " + " << s1 << " = ";
			if (s1.size() > s.size())s = add(s1, s);
			else s = add(s, s1);
			cout << s << endl;
		}
		else break;
	}
	if (i == 10)printf("Not found in 10 iterations.");
	else cout << s << " is a palindromic number.";
	system("pause");
	return 0;
}