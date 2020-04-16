#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
void query(map<string, set<string>>&m, string &s) {
	if (m.find(s) != m.end())
		for (auto it = m[s].begin(); it != m[s].end(); it++)
			cout << *it << endl;
	else
		cout << "Not Found" << endl;
}
int main() {
	int n;
	cin >> n;
	map<string, set<string>>title,author,key,pub,year;
	for (int i = 0; i < n; i++) {
		string id;
		cin >> id;
		getchar();
		string t;
		getline(cin, t);
		title[t].insert(id);
		getline(cin, t);
		author[t].insert(id);
		while (cin >> t) {
			key[t].insert(id);
			char c = getchar();
			if (c == '\n')break;
		}
		getline(cin, t);
		pub[t].insert(id);
		getline(cin, t);
	    year[t].insert(id);
	}
	int m;
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++) {
		string t;
		getline(cin, t);
		cout << t << endl;
		int type = t[0] - '0';
		t = t.substr(3, t.size() - 3);
		if (type == 1)query(title, t);
		else if (type == 2)query(author, t);
		else if (type == 3)query(key, t);
		else if (type == 4)query(pub, t);
		else if (type == 5)query(year, t);
	}
	system("pause");
	return 0;
}