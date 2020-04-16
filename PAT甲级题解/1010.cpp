#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	string n[2];
	int tag, radix;
	cin >> n[0] >> n[1] >> tag >> radix;
	long long m[2] = { 0 };
	int length = n[tag - 1].length();
	for (int i = length - 1; i >= 0; i--) {
		if (isalpha(n[tag - 1][i])) {
			int t = n[tag - 1][i] - 'a' + 10;
			m[tag - 1] += t * pow(radix, length - i - 1);
		}
		else m[tag - 1] += (n[tag - 1][i] - '0') * pow(radix, length - i - 1);
	}
	vector<int>q, v;
	int tag1;
	if (tag == 1)tag1 = 1;
	else tag1 = 0;
	for (int i = 0; i < n[tag1].length(); i++) {
		if (isalpha(n[tag1][i])) {
			int t = n[tag1][i] - 'a' + 10;
			q.push_back(t);
		}
		else q.push_back(n[tag1][i] - '0');
	}
	v = q;
	sort(q.begin(), q.end());
	int min = q[q.size() - 1];
	for (int i = min + 1; i <= 36; i++) {
		int j = 0;
		for (auto it = v.rbegin(); it != v.rend(); it++) {
			m[tag1] += *it * pow(i, j);
			j++;
		}
		if (m[0] == m[1]) {
			printf("%d", i);
			system("pause");
			return 0;
		}
		m[tag1] = 0;
	}
	printf("Impossible");
	system("pause");
	return 0;
}