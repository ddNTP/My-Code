#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int graph[105][105];
int N, M;
void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] |= graph[i][k] & graph[k][j];
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1][t2] = 1;
	}
	floyd();
	int res = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) 
			if (graph[i][j] || graph[j][i])cnt++;
		if (cnt == N - 1)res++;
	}
	cout << res << endl;
	system("pause");
	return 0;
}