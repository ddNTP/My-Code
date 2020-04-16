#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int cnt = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			if (cnt == 0) {
				ans = t;
				cnt = 1;
			}
			else if (ans == t) 
				cnt++;
			else cnt--;
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}