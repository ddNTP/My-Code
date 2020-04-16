#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int lay;
	vector<int>child;
}no[110];
int laycnt[110] = { 0 };
void reckon(int root) {
	if (root == 1) {
		no[root].lay = 1;
		laycnt[no[root].lay]++;
	}
	for (int i = 0; i < no[root].child.size(); i++) {
		int t = no[root].child[i];
		no[t].lay = no[root].lay + 1;
		laycnt[no[t].lay]++;
		reckon(t);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int id, cnt;
		cin >> id >> cnt;
		for (int j = 0; j < cnt; j++) {
			int t;
			cin >> t;
			no[id].child.push_back(t);
		}
	}
	reckon(1);
	int max = 0;
	for (int i = 1; i < 110; i++) 
		if (laycnt[i] > max)max = laycnt[i];
	int ans;
	for (ans = 1; ans < 110; ans++) 
		if (laycnt[ans] == max)break;
	printf("%d %d", laycnt[ans], ans);
	system("pause");
	return 0;
}