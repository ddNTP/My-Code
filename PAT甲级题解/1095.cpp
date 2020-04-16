#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int cnt[100000] = { 0 }; 
struct node
{
	char id[8];
	int time;
	char status[4];
}car[10010], value[10010];
int time_to_time(int h, int m, int s) {
	return 3600 * h + 60 * m + s;
}
bool cmp1(node a, node b) {
	if (strcmp(a.id, b.id) != 0)return strcmp(a.id, b.id) < 0;
	else return a.time < b.time;
}
bool cmp2(node a, node b) {
	return a.time < b.time;
}
int main() {
	int n, k;
	scanf_s("%d%d", &n, &k);
	map<string, int>parktime;
	for (int i = 0; i < n; i++) {
		int hh, mm, ss;
		scanf_s("%s %d:%d:%d %s", car[i].id, 20, &hh, &mm, &ss, car[i].status,10);
		int time = time_to_time(hh, mm, ss);
		car[i].time = time;
	}
	sort(car, car + n, cmp1);
	int maxtime = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!strcmp(car[i].id, car[i + 1].id) && !strcmp(car[i].status, "in") && !strcmp(car[i + 1].status, "out")) {
			if (parktime.count(car[i].id) == 0)parktime[car[i].id] = car[i+1].time-car[i].time;
			else 
				parktime[car[i].id] =parktime[car[i].id]+car[i + 1].time - car[i].time;
			value[count] = car[i];
			value[count + 1] = car[i + 1];
			count += 2;
			maxtime = max(maxtime, parktime[car[i].id]);
		}
	}
	sort(value, value + count, cmp2);
	int m = 0;
	for (int i = 1; i <= k; i++) {
		int hh, mm, ss;
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		int time = time_to_time(hh, mm, ss);
		for (;; m++) {
			if (m == count)break;
			if (time < value[m].time)break;
			if (!strcmp(value[m].status, "in"))cnt[i]++;
			if (!strcmp(value[m].status, "out"))cnt[i]--;
		}
		cnt[i] += cnt[i - 1];
		printf("%d\n", cnt[i]);
	}
	for (auto it=parktime.begin(); it != parktime.end(); it++) {
		if (it->second == maxtime)cout << it->first<<" ";
	}
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime / 60 % 60, maxtime % 60);
	system("pause");
	return 0;
}