#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
struct Node
{
	int addr, data, next, order;
	bool flag;
}node[100010];
bool have[100010];
bool cmp1(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	int addr, n;
	cin >> addr >> n;
	for (int i = 0; i < 100010; i++)
		node[i].order = 9999999;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cin >> node[t].data >> node[t].next;
		node[t].addr = t;
	}
	int cnt = 0;
	while (addr != -1) {
		node[addr].order = ++cnt;
		addr = node[addr].next;
	}
	sort(node, node + 100010, cmp1);
	for (int i = 0; i < cnt; i++) {
		int t = abs(node[i].data);
		if (!have[t])have[t] = true;
		else node[i].flag = true;
	}
	vector<Node>v1,v2;
	for (int i = 0; i < cnt; i++) {
		if (!node[i].flag)v1.push_back(node[i]);
		else v2.push_back(node[i]);
	}
	for (int i=0; i < v1.size(); i++) {
		if (i != v1.size() - 1) {
			v1[i].next = v1[i + 1].addr;
			printf("%05d %d %05d\n", v1[i].addr, v1[i].data, v1[i].next);
		}
		else {
			v1[i].next = -1;
			printf("%05d %d -1\n", v1[i].addr, v1[i].data);
		}
	}
	for (int i = 0; i < v2.size(); i++) {
		if (i != v2.size() - 1) {
			v2[i].next = v2[i + 1].addr;
			printf("%05d %d %05d\n", v2[i].addr, v2[i].data, v2[i].next);
		}
		else {
			v2[i].next = -1;
			printf("%05d %d -1\n", v2[i].addr, v2[i].data);
		}
	}
	if (v1.size() == 0 && v2.size() == 0)printf("-1");
	system("pause");
	return 0;
}