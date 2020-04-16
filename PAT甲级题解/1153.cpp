#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	string id;
	int score;
};
bool cmp(node a, node b) {
	return a.score != b.score ? a.score > b.score:a.id < b.id;
}
struct node1
{
	int site;
	int num;
};
bool cmp1(node1 a, node1 b) {
	return a.num != b.num ? a.num > b.num:a.site < b.site;
}
int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, vector<node>>mp[3];
	unordered_map<int, vector<int>>mp1;
	for (int i = 0; i < n; i++) {
		string s;
		int t;
		cin >> s >> t;
		mp[1][s[0]].push_back(node{ s,t });
		mp[2][stoi(s.substr(1, 3))].push_back(node{ s,t });
		mp1[stoi(s.substr(4, 6))].push_back(stoi(s.substr(1, 3)));
	}
	for (int i = 0; i < m; i++) {
		int type;
		string term1;
		cin >> type >> term1;
		switch (type)
		{
		case 1: {
			char term = term1[0];
			printf("Case %d: %d %c\n", i + 1, type, term);
			if (mp[1][term].size() == 0) {
				printf("NA\n");
				break;
			}
			sort(mp[1][term].begin(), mp[1][term].end(), cmp);
			for (int j = 0; j < mp[1][term].size(); j++)
				cout << mp[1][term][j].id << " " << mp[1][term][j].score << endl;
			break;
		}
		case 2: {
			int term = stoi(term1);
			printf("Case %d: %d %03d\n", i + 1, type, term);
			int total = 0;
			if (mp[2][term].size() == 0) {
				printf("NA\n");
				break;
			}
			for (int j = 0; j < mp[2][term].size(); j++)
				total += mp[2][term][j].score;
			cout << mp[2][term].size() << " " << total << endl;
			break;
		}
		case 3: {
			int term = stoi(term1);
			printf("Case %d: %d %06d\n", i + 1, type, term);
			if (mp1[term].size() == 0) {
				printf("NA\n");
				break;
			}
			vector<node1>v1;
			unordered_map<int, int>mp2;
			for (int j = 0; j < mp1[term].size(); j++) {
				mp2[mp1[term][j]]++;
			}
			for (auto it = mp2.begin(); it != mp2.end(); it++) {
				v1.push_back(node1{ it->first,it->second });
			}
			sort(v1.begin(), v1.end(), cmp1);
			for (int j = 0; j < v1.size(); j++) {
				printf("%03d %d\n", v1[j].site, v1[j].num);
			}
			break;
		}
		}
	}
	system("pause");
	return 0;
}