#include<unordered_map>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main() {
	string s1;
	cin >> s1;
	string s2;
	cin >> s2;
	unordered_map<char, int>a;
	char m;
	for (int i = 0; i < s2.length(); i++) {
		if (isalpha(s2[i]))m = toupper(s2[i]);
		else m = s2[i];
		a[m] = 1;
	}
	for (int i = 0; i < s1.length(); i++) {
		if(isalpha(s1[i]))m = toupper(s1[i]);
		else m = s1[i];
		if (a.count(m) == 0) {
			printf("%c", m);
			a[m] = 1;
		}
	}
	system("pause");
	return 0;
}