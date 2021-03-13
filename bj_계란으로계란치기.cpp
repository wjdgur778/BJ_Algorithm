#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<pair<int, int>>vec;
vector<bool>check(10, false);
int answer = 0;
void dfs(int cnt) {
	//cout << cnt << endl;
	if (cnt >= n) {
		int tmp = 0;
		for (int i = 0; i <n; i++)if (vec[i].first <= 0)tmp++;
		answer = max(answer, tmp);
		return;
	}

	if (vec[cnt].first <= 0)dfs(cnt + 1);
	else {
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (cnt != i && vec[i].first > 0) {
				vec[cnt].first -= vec[i].second;
				vec[i].first -= vec[cnt].second;
				f = false;
				dfs(cnt + 1);
				vec[cnt].first += vec[i].second;
				vec[i].first += vec[cnt].second;
			}
		}
		if (f)dfs(cnt+1);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		int b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	dfs(0);
	cout << answer;
	return 0;
}