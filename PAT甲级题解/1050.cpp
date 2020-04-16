#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main() {
	unordered_map<char, int>a;
	string b;
	getline(cin, b);
	string c;
	getline(cin, c);
	for (int i = 0; i < c.length(); i++) 
		a[c[i]] = 1;
	for (int i = 0; i < b.length(); i++) 
		if (a.count(b[i]) == 0)printf("%c", b[i]);
	system("pause");
	return 0;
}