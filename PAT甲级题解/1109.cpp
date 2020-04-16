#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	string name;
	int height;
};
bool cmp1(node a, node b) {
	if (a.height != b.height)
		return a.height > b.height;
	else
		return a.name < b.name;
}
vector<node>v;
node gra[20][10010];
int main() {
	int n, k;
	cin >> n >> k;
	int num = n / k;
	for (int i = 0; i < n; i++) {
		node a;
		cin >> a.name >> a.height;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp1);
	int last = n - num * (k - 1);
	int mid = last / 2 + 1;
	gra[0][mid] = v[0];
	int left = -1, right = 1;
	int y = mid;
	int i = 1;
	for (; i < last; i++) {
		if (i % 2 == 1) {
			y = mid + left;
			left--;
		}
		else {
			y = mid + right;
			right++;
		}
		gra[0][y] = v[i];
	}
	for (int j = 1; j <= last; j++) {
		cout << gra[0][j].name;
		if (j != last)cout << " ";
	}
	cout << endl;
	mid = num / 2 + 1;
	for (int x = 1; x < k; x++) {
		y = mid;
		gra[x][y] = v[i];
		int j = i + 1;
		left = -1, right = 1;
		for (; j < i + num; j++) {
			if ((j - i) % 2 == 1) {
				y = mid + left;
				left--;
			}
			else {
				y = mid + right;
				right++;
			}
			gra[x][y] = v[j];
		}
		i = j;
	}
	for (int a = 1; a < k; a++) {
		for (int b = 1; b <= num; b++) {
			cout << gra[a][b].name;
			if (b != num)cout << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}