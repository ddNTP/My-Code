#include<iostream>
#include<math.h>
#include<string>
using namespace std;
bool isprime(int n) {
	if (n < 2)return false;
	int t = sqrt(n);
	for (int i = 2; i <= t; i++)
		if (n%i == 0)return false;
	return true;
}
int award[10000];
int main() {
	string s[5] = { "Are you kidding?","Mystery Award","Minion","Chocolate","Checked" };
	int n, k;
	cin >> n;
	int one;
	cin >> one;
	award[one] = 1;
	for (int i = 2; i <= n; i++) {
		int t;
		cin >> t;
		if (isprime(i))award[t] = 2;
		else award[t] = 3;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		printf("%04d: ", t);
		cout << s[award[t]] << endl;
		if (award[t] != 0)award[t] = 4;
	}
	system("pause");
	return 0;
}