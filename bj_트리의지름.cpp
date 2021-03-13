#include<iostream>
#include<vector>
using namespace std;
int n;
int tmp = 0;
int answer = 0;
int v1, v2;

vector<pair<int, int>>tree[100001];
vector<bool>check;
int path;


// 트리의 지름을 구하는 방법
// 어떤 임의의 점을 시작으로 (a) -> v1 (가중치 합이 최대인 순간) v1 -> v2 (가중치 합이 최대인 순간)  

void dfs(int n, int sum) {

	if (tmp < sum) {
		tmp = sum;
		path = n;
	}

	for (int i = 0; i < tree[n].size(); i++) {
		int next = tree[n][i].first;
		int cost = sum + tree[n][i].second;
		if (check[next] == false) {
			check[next] = true;
			dfs(next, cost);
		}
	}
	return;
}
void find(int n, int sum) {

	if (n == v2) {
		cout << sum;
		return;
	}

	for (int i = 0; i < tree[n].size(); i++) {
		int next = tree[n][i].first;
		int cost = sum + tree[n][i].second;
		if (check[next] == false) {
			check[next] = true;
			find(next, cost);
		}
	}
	return;
}

int main() {
	cin >> n;
	int a;
	for (int i = 1; i <= n; i++) {
		int b;
		int c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)break;
			cin >> c;
			tree[a].push_back({ b,c });
		}
	}
	
	vector<bool>t(100001, false);
	//v1이 나오고
	check = t;
	check[a] = true;
	dfs(a,0);
	v1 = path;

	//v1 -> v2 r
	check = t;
	check[v1] = true;
	dfs(v1, 0);
	cout << tmp;

	return 0;
}