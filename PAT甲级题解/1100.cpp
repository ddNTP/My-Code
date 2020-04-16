#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	int n;
	map<string, int>m1,m2;
	scanf_s("%d\n", &n);
	string num1[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string num2[13] = { " ","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	for (int i = 0; i < 13; i++) {
		m1[num1[i]] = i;
		if (i != 0)m2[num2[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		string s1;
		getline(cin, s1);
		if (s1[0] >= '0'&&s1[0] <= '9') {
			int n = stoi(s1);
			if (n == 0) {
				cout << num1[0] << endl;
				continue;
			}
			int j = 0;
			if (n >= 13) {
				int t = n / 13;
				cout << num2[t];
				t = n % 13;
				if(t!=0)cout << " " << num1[t];
			}
			else {
				cout << num1[n];
			}
			cout << endl;
		}
		else {
			string a = s1.substr(0, 3),b;
			if (s1.size() > 4)b = s1.substr(4, 3);
			if (s1.size() > 4) {
				int t = m2[a] * 13 + m1[b];
				cout << t << endl;
			}
			else {
				if (m1.find(a) != m1.end()) {
					cout << m1[a] << endl;
				}
				else
				{
					cout << m2[a] * 13 << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}