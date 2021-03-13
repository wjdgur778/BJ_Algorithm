#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int>>vec;
int INF = 100009;
vector<int>costomer(1100, INF);
vector<bool >check (1100, false);
int c;
int n;
int answer=INF;

//기본적인 1차원 행렬에서의 dfs 사용 -> 이후 dp 적용시키기
//

void dfs(int n, int sum) {
	cout << n << " ";
	if (c <= n) {
		answer = answer < sum ? answer : sum;
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		int cost =sum + vec[i].first;
		int next = n + vec[i].second;
		if (costomer[next] == INF) {
			costomer[next] = cost;
			dfs(next, cost);
		}
		else {
			if (costomer[next] <= cost)continue;
			else {
				costomer[next] = cost;
				dfs(next, cost);
			}
		}
	}
}
int main() {
	cin >> c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		int b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	dfs(0, 0);
	cout << answer;

	return 0;
}

