#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int M, N;
int color[20][20], cur[20][20];
int ans[20][20], tmp[20][20], ansstep=0x3fffffff, tmpstep;
void press(int i, int j) {
	cur[i][j] ^= 1;
	cur[i - 1][j] ^= 1;
	cur[i + 1][j] ^= 1;
	cur[i][j + 1] ^= 1;
	cur[i][j - 1] ^= 1;
}
bool solve() {
	memcpy(cur, color, sizeof(color));
	for (int i = 1; i <= N; i++)
		if (tmp[1][i]) {
			press(1, i);
			tmpstep++;
		}
	for (int i = 2; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (cur[i - 1][j]) {
				tmp[i][j] = 1;
				press(i, j);
				tmpstep++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (cur[M][i])return false;
	return true;
}
int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) 
		for (int j = 1; j <= N; j++) 
			scanf("%d", &color[i][j]);
	for (int i = 0; i < (1 << N); i++) {
		tmpstep = 0;
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j < N; j++) 
			tmp[1][N - j] = i >> j & 1;
		if (solve() && tmpstep < ansstep) {
			memcpy(ans, tmp, sizeof(tmp));
			ansstep = tmpstep;
		}
	}
	if (ansstep != 0x3fffffff) {
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				printf("%d", ans[i][j]);
				if (j != N)printf(" ");
			}
			printf("\n");
		}
	}
	else
		printf("IMPOSSIBLE\n");
	system("pause");
	return 0;
}