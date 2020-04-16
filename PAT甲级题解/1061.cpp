#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
int main() {
	string s[4];
	string a[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	int n1 = min(s[0].size(), s[1].size());
	int n2 = min(s[2].size(), s[3].size());
	int i;
	for (i = 0; i < n1; i++) {
		if (s[0][i] == s[1][i]&&(s[0][i]>='A'&&s[0][i]<='G')) {
				break;
		}
	}
	string week = a[s[0][i] - 'A'];
	for (i++; i < n1; i++) {
		if (s[0][i] == s[1][i]&& (isdigit(s[0][i])||(s[0][i]<='N'&&s[0][i]>='A'))) {
			break;
		}
	}
	int hh;
	if (isdigit(s[0][i]))hh = s[0][i] - '0';
	if (isalpha(s[0][i]))hh = 10 + s[0][i] - 'A';
	for (i = 0; i < n2; i++) {
		if (isalpha(s[2][i]) && isalpha(s[3][i])) {
			if(s[2][i]==s[3][i])break;
		}
	}
	cout << week << " ";
	printf("%02d:%02d", hh, i);
	system("pause");
	return 0;
}