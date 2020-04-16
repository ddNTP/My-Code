#include<iostream>
#include<string>
#include<math.h>
using namespace std;
bool isprime(int n) {
	if (n < 2)return false;
	int q = sqrt(n);
	for (int i = 2; i <= q; i++) 
		if (n%i == 0)return false;
	return true;
}
int main() {
	int l, k;
	cin >> l >> k;
	string s;
	cin >> s;
	int i = 0;
	while (s[i] == '0')i++;
	for (; i <= l - k; i++) {
		int t = stoi(s.substr(i, k));
		if (isprime(t)) {
			cout << s.substr(i, k);
			system("pause");
			return 0;
		}
	}
	printf("404");
	system("pause");
	return 0;
}