#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
const int maxn = 100;
int main() {
	int n;
	cin >> n;
	int id = 0;
	while (id++<n) {
		int C;
		cin >> C;
		queue<char>s1;
		queue<char>s2;
		queue<char>s12;
		getchar();
		for (int i = 0; i < C; i++) {
			char c;
			scanf("%c", &c);
			s1.push(c);
		}
		getchar();
		for (int i = 0; i < C; i++) {
			char c;
			scanf("%c", &c);
			s2.push(c);
		}
		getchar();
		for (int i = 0; i < 2 * C; i++) {
			char c;
			scanf("%c", &c);
			s12.push(c);
		}
		getchar();
		int res = 1;
		while (res<maxn) {
			queue<char>ts12;
			for (int j = 0; j < C; j++) {
				ts12.push(s2.front());
				ts12.push(s1.front());
				s1.pop();
				s2.pop();
			}
			if (ts12 == s12)
				break;
			else {
				for (int i = 0; i < C; i++) {
					s1.push(ts12.front());
					ts12.pop();
				}
				for (int i = 0; i < C; i++) {
					s2.push(ts12.front());
					ts12.pop();
				}
			}
			res++;
		}

		if(res<maxn)printf("%d %d\n", id, res);
		else printf("%d -1\n", id);
	}
	system("pause");
	return 0;
}