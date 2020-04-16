#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int t1, t2;
		t1 = stoi(s.substr(0, s.size() / 2));
		t2 = stoi(s.substr(s.size() / 2, s.size() / 2));
		int t3 = t1 * t2;
		int t4 = stoi(s);
		if (!t3 || !t4) {
			printf("No\n");
			continue;
		}
		if (t4%t3 == 0)printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}