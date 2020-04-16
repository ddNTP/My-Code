#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
map<string, bool>have;
vector<string>ans;
int main() {
	int m, n, s;
	cin >> m >> n >> s;
	for (int i = 1; i <= m; i++) {
		string str;
		cin >> str;
		if (i - s >= 0 && (i - s) % n == 0) {
			if (have[str]) {
				s++;
				continue;
			}
			else {
				have[str] = true;
				ans.push_back(str);
			}
		}
	}
	if (ans.size() == 0) {
		cout << "Keep going...";
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	system("pause");
	return 0;
}