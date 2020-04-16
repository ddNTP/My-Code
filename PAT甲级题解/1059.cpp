#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
bool isprime(ll n) {
	if (n <= 1)return false;
	ll sqr = sqrt(n*1.0);
	for (ll i = 2; i <= sqr; i++)
		if (n%i == 0)return false;
	return true;
}
int main() {
	ll n;
	cin >> n;
	if (n == 1) {
		printf("1=1"); 
		system("pause");
		return 0;
	}
	ll m = n;
	ll sqr = sqrt(n*1.0);
	if (isprime(n)) {
		printf("%lld=%lld", n, n);
		system("pause");
		return 0;
	}
	vector<ll>cof, exp;
	for (ll i = 2; i<sqr&&n>1; i++) {
		if (!isprime(i))continue;
		ll cnt = 0;
		bool flag = false;
		while (1) {
			if (n%i == 0) {
				n /= i;
				cnt++;
				flag = true;
			}
			else break;
		}
		if (flag) {
			cof.push_back(i);
			exp.push_back(cnt);
		}
	}
	printf("%lld=",m);
	for (int i = 0; i < cof.size(); i++) {
		if (i != 0)printf("*");
		if (exp[i] > 1)
			printf("%lld^%lld", cof[i], exp[i]);
		else printf("%lld", cof[i]);
	}
	system("pause");
	return 0;
}