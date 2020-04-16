#include<iostream>
#include<queue>
using namespace std;
struct Node
{
	int x, y, z;
}node,node1;
int marix[1286][128][60];
int x[6] = { 1,-1,0,0,0,0 };
int y[6] = { 0,0,1,-1,0,0 };
int z[6] = { 0,0,0,0,1,-1 };
int m, n, l, t, maxsum = -1;
bool inq[1286][128][60];
bool judge(Node a) {
	if (a.x >= m || a.y >= n || a.z >= l || a.x < 0 || a.y < 0 || a.z < 0) return false;
	if (marix[a.x][a.y][a.z] == 0)return false;
	if (inq[node1.x][node1.y][node1.z] == true)return false;
	return true;
}
int bfs() {
	queue<Node>q;
	int tot = 0;
	q.push(node);
	inq[node.x][node.y][node.z] = true;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		tot++;
		for (int i = 0; i < 6; i++) {
			node1.x = node.x + x[i];
			node1.y = node.y + y[i];
			node1.z = node.z + z[i];
			if (judge(node1)) {
				inq[node1.x][node1.y][node1.z] = true;
				q.push(node1);
			}
		}
	}
	return tot;
}
int main() {
	cin >> m >> n >> l >> t;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				scanf_s("%d", &marix[j][k][i]);
			}
		}
	}
	int count, sum=0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (marix[j][k][i] == 1&&!inq[j][k][i]) {
					node.x = j;
					node.y = k;
					node.z = i;
					count = bfs();
					if (count >= t)sum += count;
				}
			}
		}
	}
	printf("%d", sum);
	system("pause");
	return 0;
}