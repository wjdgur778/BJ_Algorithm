#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<int>vec[101];
vector<int>vec_a[101];

vector<bool>check(101, false);

bool is_mid = true;
int cnt = 0;
void dfs(int n,vector<int>vec[101]) {
	cnt++;
	for (int i = 0; i < vec[n].size(); i++) {
		if (check[vec[n][i]] == false) {
			check[vec[n][i]] = true;
			dfs(vec[n][i], vec);
		}

	}
}
int main() {
	cin >> n >> m;
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec_a[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		vector<bool>tmp(101, false);
		check = tmp;
		check[i] = true;
		dfs(i,vec);
		//cout << cnt << " ";
		if (cnt > (n + 1) / 2)answer++;
	}
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		vector<bool>tmp(101, false);
		check = tmp;
		check[i] = true;
		dfs(i, vec_a);
		//cout << cnt << " ";
		if (cnt > (n + 1) / 2)answer++;
	}
	cout << answer;
	return 0;
}