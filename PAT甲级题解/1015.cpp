#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n) {
	if (n <= 1)return false;
	int sqr = sqrt(n*1.0);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false; 
	}
	return true;
}
int num[1001];
int main() {
	int n, d;
	while (scanf("%d", &n) != EOF) {
		if (n < 0)break;
		cin >> d;
		if (!isprime(n)) {
			printf("No\n"); continue;
		}
		int len = 0;
		do {
			num[len++] = n % d;
			n = n / d;
		} while (n != 0);
		for (int i = 0; i < len; i++) {
			n = n * d + num[i];
		}
		if (isprime(n))printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}