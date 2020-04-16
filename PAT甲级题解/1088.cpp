#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b == 0 ? abs(a) : gcd(b, a%b);
}
void fun(ll a, ll b) {
	if (a==0||b==0) {
		if (b == 0) {
			printf("Inf"); return;
		}
		else {
			printf("0"); return;
		}
	}
	if (b < 0) {
		a = -a;
		b = -b;
	}
	if (a < 0) 
		cout << "(";
	ll gcdvalue = gcd(a, b);
	a /= gcdvalue;
	b /= gcdvalue;
	ll integer = a / b;
	a = a - b * integer;
	if (integer != 0)a = abs(a);
	if (integer == 0 && a == 0) {
		cout << "0"; return;
	}
	if (integer != 0) {
		cout << integer;
		if (a == 0) {
			if (integer <= 0)cout << ")";
			return ;
		}
		cout << " ";
	}
	printf("%lld/%lld", a, b);
	if (integer < 0 || a < 0)cout << ")";
}
int main() {
	ll a, b, c, d;
	scanf_s("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	fun(a, b); printf(" + "); fun(c, d); printf(" = "); fun(a*d + b * c, b*d); cout << endl;
	fun(a, b); printf(" - "); fun(c, d); printf(" = "); fun(a*d - b * c, b*d); cout << endl;
	fun(a, b); printf(" * "); fun(c, d); printf(" = "); fun(a*c, b*d); cout << endl;
	fun(a, b); printf(" / "); fun(c, d); printf(" = "); fun(a*d, b*c); cout << endl;
	system("pause");
	return 0;
}