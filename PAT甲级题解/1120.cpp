#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool have[100];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int total = 0;
		for (int i = 0; i < t.size(); i++) 
			total += (t[i] - '0');
		have[total] = true;
	}
	int num = 0;
	vector<int>v;
	for (int i = 0; i < 100; i++) 
		if (have[i]) {
			num++;
			v.push_back(i);
		}
	cout << num << endl;
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
		if (i != v.size() - 1)printf(" ");
	}
	system("pause");
	return 0;
}