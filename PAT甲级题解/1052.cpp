#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int value, addr, next, order;
}node[100010];
bool cmp1(Node a, Node b) {
	return a.value < b.value;
}
bool cmp2(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	int n, addr;
	cin >> n >> addr;
	for (int i = 0; i < 100010; i++) {
		node[i].value = 9999999;
		node[i].order = 9999999;
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cin >> node[t].value >> node[t].next;
		node[t].addr = t;
	}
	int cnt = 0;
	while (addr != -1) {
		node[addr].order = ++cnt;
		addr = node[addr].next;
	}
	sort(node, node + 100010, cmp2);
	sort(node, node + cnt, cmp1);
	for (int i = 0; i < cnt - 1; i++)
		node[i].next = node[i + 1].addr;
	node[cnt - 1].next = -1;
	if (cnt == 0) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", cnt, node[0].addr);
	for (int i = 0; i < cnt - 1; i++)
		printf("%05d %d %05d\n", node[i].addr, node[i].value, node[i].next);
	printf("%05d %d -1", node[cnt - 1].addr, node[cnt - 1].value);
	system("pause");
	return 0;
}