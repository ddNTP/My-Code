#include<iostream>
#include<string>
using namespace std;
const int mod = 1000000007;
const int MAXN = 100010;
int main() {
	string s;
	cin >> s;
	int  rightT[MAXN] = { 0 }, leftP[MAXN] = { 0 };
	for (int i = 0; i < s.length(); i++) 
		if (s[i] == 'P')leftP[i + 1] = leftP[i] + 1;
		else leftP[i + 1] = leftP[i];
	int ans = 0;
	for (int i = s.length() - 1; i > 0; i--) {
		if (s[i] == 'T')rightT[i - 1] = rightT[i] + 1;
		else rightT[i - 1] = rightT[i];
		if (s[i] == 'A')ans =(ans+ leftP[i] * rightT[i])%mod;
	}
	cout << ans;
	system("pause");
	return 0;
}