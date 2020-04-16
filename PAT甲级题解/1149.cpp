#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	map<int,vector<int>>no;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		no[t1].push_back(t2);
		no[t2].push_back(t1);
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		int have[100001] = { 0 };
		bool flag = true;
		vector<int>tmp;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			have[t] = 1;
			tmp.push_back(t);
		}
		for(int j=0;j<k;j++){
			for (int a = 0; a < no[tmp[j]].size(); a++) 
				if (have[no[tmp[j]][a]])flag = false;
			if (!flag)break;
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}