#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int M;
vector < pair<int, pair<int, int>>>network;
vector<int>check(1001);
int answer = 0;
int get_p(int n) {
	if (check[n] == n)return n;
	else return check[n] = get_p(check[n]);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		network.push_back({ c,{a,b} });
	}
	for (int i = 1; i <= N; i++)check[i] = i;

	sort(network.begin(), network.end());

	for (int i = 0; i < M; i++) {
		int a = get_p(network[i].second.first);
		int b = get_p(network[i].second.second);
		int c = network[i].first;
		if (a != b) {
			if (a < b) check[b] = a;
			else check[a]= b;
			answer += c;
		}
	}
	cout<<answer;

	return 0;
}