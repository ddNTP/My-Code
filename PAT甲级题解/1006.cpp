#include<iostream>
#include<climits>
#include<string>
using namespace std;
int minn = INT_MAX, maxn = INT_MIN;
string signin, signout;
int main() {
	int m;
	scanf("%d", &m);
	string id;
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		int h1, h2, m1, m2, s1, s2;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		int time1, time2;
		time1 = 3600 * h1 + 60 * m1 + s1;
		time2 = 3600 * h2 + 60 * m2 + s2;
		if (time1 < minn) {
			minn = time1;
			signin = t;
		}
		if (time2 > maxn) {
			maxn = time2;
			signout = t;
		}
	}
	cout << signin << " " << signout;
	return 0;
}