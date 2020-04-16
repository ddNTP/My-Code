#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
bool seq[100010];
int main() { 
	int n;
	cin >> n;
	int a;
	int now;
	int c[100010];
	int b[100010];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		c[a] = i;
		b[i] = a;
		if (a == i)seq[a] = true;
		if (a == 0)now = i;
	}
	int cnt = 0;
	int s = 1;
	while (1) {
		if (seq[0]) {
			for (; s < n; s++) {//不能每次循环从头开始
				if (!seq[s])break;
			}
			if (s == n) {
				printf("%d", cnt);
				system("pause");
				return 0;
			}
			seq[0] = false;
			
			c[0] = s;
			c[b[s]] = 0;
			b[0] = b[s];
			b[s] = 0;
			now = s;
			cnt++;
		}
		seq[now] = true;
		now = c[now];
		cnt++;
		if(now!=0)seq[now] = false;
		else seq[now] = true;
	}
	return 0;
}