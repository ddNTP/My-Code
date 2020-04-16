#include<iostream>
#include<stack>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	stack<int>s;
	int a[1010] = {0};
	while (k--) {
		while (!s.empty())
			s.pop();
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		int current = 0;
		for (int i = 1; i <= n; i++) {
			s.push(i);
			if (s.size() > m)break;
			while (!s.empty()&&s.top() == a[current]) {
				s.pop();
				current++;
			}
		}
		if (s.empty()) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	system("pause");
}