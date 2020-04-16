#include<iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
	int now = 1, a = 1;
	int left = 0, right = 0;
	int ans=0;
	long long m = n;
	while (m!=0)
	{
		now = n / a % 10;
		left = n / a / 10;
		right = n % a;
		if (now == 0)ans += left * a;
		else if (now == 1)ans += (left*a + right + 1);
		else ans += (left + 1)*a;
		a = a * 10;
		m = m / 10;
	}
	cout << ans;
	return 0;
}