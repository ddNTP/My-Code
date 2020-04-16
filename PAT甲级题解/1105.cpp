#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
vector<int>v;
int gra[1000][1000];
int locx[4] = { 0,1,0,-1 };
int locy[4] = { 1,0,-1,0 };
bool cmp1(int a, int b) {
	return a > b;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp1);
	int n = sqrt(N), m;
	for (; n > 0; n--) {
		bool flag = false;
		for (m = n; m <= N; m++) {
			if (n*m > N)break;
			if (n*m == N) {
				flag = true;
				break;
			}
		}
		if (flag)break;
	}
	int mov = 0;
	int x = 0, y = 0;
	for (int i = 0; i < N; i++) {
		gra[x][y] = v[i];
		if (i == N - 1)break;
		if ((x + locx[mov] >= m)||(x+locx[mov]<0)) {
			mov = (mov + 1) % 4;
		}
		else if(y+locy[mov]>=n||(y+locy[mov]<0)){
			mov = (mov + 1) % 4;
		}
		if (gra[x + locx[mov]][y + locy[mov]] != 0) {
			mov = (mov + 1) % 4;
		}
		x = x + locx[mov];
		y = y + locy[mov];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", gra[i][j]);
			if (j != n - 1)printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}