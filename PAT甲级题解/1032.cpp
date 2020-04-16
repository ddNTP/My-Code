#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int next, addr;
	char data;
	int order;
}node[100010];
bool cmp2(Node a, Node b) {
	return a.order < b.order;
}
bool have[100010];
int main() {
	int addr1, addr2, n;
	cin >> addr1 >> addr2 >> n;
	for (int i = 0; i < 100010; i++) {
		node[i].order = 9999999;
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cin >> node[t].data >> node[t].next;
		node[t].addr = t;
	}
	int t1=addr1, t2=addr2;
	int cnt = 0;
	vector<int>v;
	while (t1 != -1) {
		have[t1] = true;
		t1 = node[t1].next;
	}
	while (t2 != -1) {
		node[t2].order = ++cnt;
		t2 = node[t2].next;
	}
	sort(node, node + 100010, cmp2);
	int i;
	for ( i = 0; i < cnt; i++) 
		if (have[node[i].addr])break;
	if (i == cnt)
		printf("-1");
	else
		printf("%05d", node[i].addr);
	system("pause");
	return 0;
}