#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
char s[1000];
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) 
		s[a[i]]++;
	for (int i = 0; i < b.length(); i++) 
		s[b[i]]--;
	bool flag = true;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < 1000; i++) {
		if (s[i] > 0)count1 += s[i];
		if (s[i] < 0)count2 -= s[i], flag = false;
	}
	if (flag)printf("Yes %d", count1);
	else printf("No %d", count2);
	system("pause");
	return 0;
}