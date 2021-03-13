#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>vec;
vector<bool>check(10, false);
long long answer = 0;
//빠지는 과정
//8! 중에 가장 큰거
//backtracking
//brute force
long long calc(int i) {
	int l = i;
	int r = i;
	while (check[--l] == true);
	while (check[++r] == true);
	long long sum = vec[l] * vec[r];
	return sum;
}
void dfs(int n, int cnt, long long sum) {
	if (n - 2 == cnt) {
		answer = answer <= sum ? sum : answer;
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		if (check[i] == true)continue;
		check[i] = true;
		dfs(n, cnt + 1,sum+ calc(i));
		check[i] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	dfs(vec.size(), 0, 0);
	cout << answer;
	return 0;
}