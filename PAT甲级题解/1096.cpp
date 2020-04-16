#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin >> n;
	ll sqr = sqrt(n*1.0);
	ll ansi = 0, anslen = 0;
	for (ll i = 2; i <= sqr; i++) {
		ll j = i, tmp = 1;
		while (1) {
			tmp *= j;
			if (n % tmp != 0)break;
			if (anslen < j - i + 1) {
				anslen = j - i + 1;
				ansi = i;
			}
			j++;
		}
	}
	if (anslen == 0) {
		printf("1\n%lld",n);
	}
	else {
		printf("%lld\n",anslen);
		for (int i = 0; i < anslen; i++) {
			if (i != 0)printf("*");
			printf("%d", ansi + i);
		}
	}
	system("pause");
	return 0;
}