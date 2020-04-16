#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int data, next, index;
};
node in[100010];
vector<node>ans[3], result;
int main() {
	int root, n, k;
	cin >> root >> n >> k;
	for(int i=0;i<n;i++){
		int index, data, next;
		cin >> index >> data >> next;
		in[index].data = data;
		in[index].next = next;
		in[index].index = index;
	}
	int a = root;
	while (a != -1) {
		if (in[a].data < 0)ans[0].push_back(in[a]);
		else if (in[a].data >= 0 && in[a].data <= k)ans[1].push_back(in[a]);
		else ans[2].push_back(in[a]);
		a = in[a].next;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			result.push_back(ans[i][j]);
		}
	}
	for (int i = 0; i < result.size() - 1; i++) {
		result[i].next = result[i + 1].index;
	}
	result[result.size() - 1].next = -1;
	for (int i = 0; i < result.size(); i++) {
		if(i!=result.size()-1)printf("%05d %d %05d\n", result[i].index, result[i].data, result[i].next);
		else printf("%05d %d -1\n", result[i].index, result[i].data);
	}
	system("pause");
	return 0;
}