#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<pair<int, int>, int>>vec;

bool comp(pair<pair<int,int>,int> a, pair<pair<int, int>, int> b) {
	return a.first.second < b.first.second;
}
int main() {
	int N, C, M;
	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ {a,b},c });
	}
	sort(vec.begin(), vec.end(), comp);

	return 0;
}