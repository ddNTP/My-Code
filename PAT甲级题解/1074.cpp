#include<iostream>
#include<algorithm>
using namespace std;
struct NODE
{
	int add,next;
	int data;
	int order;
}link[100010];
int n;
bool cmp1(NODE a, NODE b) {
	return a.order < b.order;
}
int main() {
	int addr, k;
	cin >> addr >> n >> k;
	for (int i = 0; i < 100010; i++) {
		link[i].order = 99999999;
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cin>>link[t].data >> link[t].next;
		link[t].add = t;
	}
	int cnt=0;
	for (int i = 0; i < n; i++) {
		if (addr == -1)break;
		link[addr].order = i + 1;
		addr = link[addr].next;
		cnt++;
	}
	sort(link, link + 100010, cmp1);
	n = cnt;
	int now;
	for (int i = 0; i < n; i++) {
		int j = i + k - 1;

		if (i%k == 0 && j < n) {
			link[i].next = link[j].next;
			for (int m = j; m > i; m--) {
				link[m].next = link[m - 1].add;
			}
			if (i != 0) { 
				link[now].next = link[j].add;
			}
			int t = j + 1;
			for (int m = i; m <= j; m++) {
				link[m].order = t;
				t--;
			}
			now = i;
		}
	}
	sort(link, link + n, cmp1);
	for (int i = 0; i < n-1; i++) {
		if (i != n - 1)printf("%05d %d %05d\n", link[i].add, link[i].data, link[i].next);
	}
	printf("%05d %d -1", link[n - 1].add, link[n - 1].data);
	system("pause");
	return 0;
}