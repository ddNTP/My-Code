#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
struct node
{
	int i, j;
	string path;
	node(int x,int y,string s):i(x),j(y),path(s){}
};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	int maze[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> maze[i][j];
	queue<node>q;
	q.push(node(0, 0, "(0, 0)\n"));
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (t.i == 4 && t.j == 4) {
			cout << t.path;
			system("pause");
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int tx = t.i + dx[i];
			int ty = t.j + dy[i];
			if (tx >= 0 && tx < 5 && ty >= 0 && ty < 5 && maze[tx][ty] == 0) {
				char a = tx + '0';
				char b = ty + '0';
				q.push(node(tx, ty, t.path + "(" + a + ", " + b + ")\n"));
				maze[tx][ty] = 1;
			}
		}
	}
	return 0;
}