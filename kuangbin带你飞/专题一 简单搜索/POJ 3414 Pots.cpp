
#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int a, b;
	string op;
	int step;
	node(int t1,int t2,string t3,int t4):a(t1), b(t2),op(t3),step(t4){}
};
bool vis[105][105];
int A, B, C;
void bfs() {
	queue<node>q;
	q.push(node(0, 0, "", 0));
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.a == C || cur.b == C) {
			cout << cur.step << endl;
			cout << cur.op;
			return;
		}
		if (!vis[A][cur.b]) {
			vis[A][cur.b] = true;
			q.push(node(A, cur.b, cur.op + "FILL(1)\n", cur.step + 1));
		}
		if (!vis[cur.a][B]) {
			vis[cur.a][B] = true;
			q.push(node(cur.a, B, cur.op + "FILL(2)\n", cur.step + 1));
		}
		if (!vis[0][cur.b]) {
			vis[0][cur.b] = true;
			q.push(node(0, cur.b, cur.op + "DROP(1)\n", cur.step + 1));
		}
		if (!vis[cur.a][0]) {
			vis[cur.a][0] = true;
			q.push(node(cur.a, 0, cur.op + "DROP(2)\n", cur.step + 1));
		}
		int tmp = cur.a + cur.b;
		if (tmp <= B&& !vis[0][tmp]) {
			vis[0][tmp] = true;
			q.push(node(0, tmp, cur.op + "POUR(1,2)\n", cur.step + 1));
		}
		if (tmp > B && !vis[tmp - B][B]) {
			vis[tmp - B][B] = true;
			q.push(node(tmp - B, B, cur.op + "POUR(1,2)\n", cur.step + 1));
		}
		if (tmp <= A && !vis[tmp][0]) {
			vis[tmp][0] = true;
			q.push(node(tmp, 0, cur.op + "POUR(2,1)\n", cur.step + 1));
		}
		if (tmp > A && !vis[A][tmp - A]) {
			vis[A][tmp - A] = true;
			q.push(node(A, tmp - A, cur.op + "POUR(2,1)\n", cur.step + 1));
		}
	}
	cout << "impossible\n";
}
int main()
{
	cin >> A >> B >> C;
	bfs();
	system("pause");
	return 0;
}