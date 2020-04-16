#include<iostream>
#include<vector>
using namespace std;
int fa[10010];
bool isroot[10010];
bool have[10010];
void init() {
	for (int i = 0; i < 10010; i++)
		fa[i] = i;
}
int findfa(int a) {
	int x = a;
	while (fa[a] != a)
		a = fa[a];
	while (x != fa[x]){
		int z = x;
		x = fa[x];
		fa[z] = a;
	}
	return x;
}
void unio(int a, int b) {
	int faa = findfa(a);
	int fab = findfa(b);
	if (faa != fab) {
		fa[faa] = fab;
	}
}
int main() {
	init();
	int n;
	cin >> n;
	vector<int>v;
	int num = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int t1;
		cin >> t1;
		if (!have[t1]) {
			v.push_back(t1);
			have[t1] = true;
		}
		for (int j = 1; j < t; j++) {
			int t2;
			cin >> t2;
			if (!have[t2]) {
				v.push_back(t2);
				have[t2] = true;
			}
			unio(t1, t2);
		}
	} 
	for (int i = 0; i < v.size(); i++) 
		isroot[findfa(v[i])] = true;
	for (int i = 0; i < 10010; i++) 
		if (isroot[i])num++;
	
	int q;
	cin >> q;
	cout << num << " " << v.size() << endl;
	for (int i = 0; i < q; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		if (findfa(t1) == findfa(t2))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	system("pause");
	return 0;
}