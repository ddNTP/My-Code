#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int w, s, id;
	node(int x,int y,int z):w(x),s(y),id(z){}
	bool operator<(const node&a)const {
		if (w == a.w)return s > a.s;
		else return w < a.w;
	}
};
void print(int x,vector<int>&pre,vector<node>&v) {
	if (x == -1)return;
	print(pre[x], pre, v);
	printf("%d\n", v[x].id);
}
int main() {
	vector<node>v;
	int id = 1;
	int w, s;
	while (scanf("%d%d", &w, &s) != EOF) 
		v.push_back(node(w, s, id++));
	sort(v.begin(), v.end());
	vector<int>dp(v.size() + 1, 1);
	vector<int>pre(v.size() + 1, -1);
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j].w<v[i].w&&v[j].s>v[i].s&&dp[j]+1>dp[i]) {
				pre[i] = j;
				dp[i] = dp[j] + 1;
			}
		}
	}
	int ansj=-1, ansnum=0;
	for (int i = 0; i < dp.size(); i++) {
		if (dp[i] > ansnum) {
			ansnum = dp[i];
			ansj = i;
		}
	}
	printf("%d\n", ansnum);
	print(ansj, pre, v);
	system("pause");
	return 0;
}