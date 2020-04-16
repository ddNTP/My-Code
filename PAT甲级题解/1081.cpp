#include<iostream>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b == 0 ? abs(a) : gcd(b, a%b);
}
int main() {
	ll n, suma = 0, sumb = 1, a, b;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		scanf_s("%lld/%lld", &a, &b);
		ll gcdvalue = gcd(a, b);
		a = a / gcdvalue;
		b = b / gcdvalue;
		suma = a * sumb + suma * b;
		sumb = b * sumb;
		gcdvalue = gcd(suma, sumb);
		suma /= gcdvalue;
		sumb /= gcdvalue;
	}
	ll integer = suma / sumb;
	a = suma - integer * sumb;
	if (integer != 0) {
		cout << integer;
		if (a != 0) {
			cout << " " << a << "/" << sumb;
		}
	}
	if (integer == 0) {
		if (a != 0)cout << a << "/" << sumb;
		else cout << "0";
	}
	system("pause");
	return 0;
}