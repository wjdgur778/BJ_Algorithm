#include<iostream>
#include<vector>
using namespace std;

int N;
vector<pair<int,int>>vec;
vector < pair<int, int>>stak;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back({ a,i });
	}
	vector<int>answer(N, -1);

	stak.push_back(vec[0] );
	for (int i = 1; i < N; i++) {
		while(stak.size() != 0&&stak.back().first < vec[i].first) {
			answer[stak.back().second] = vec[i].first;
			stak.pop_back();
		}
		stak.push_back(vec[i]);
	}
	for (int i = 0; i < N; i++)cout << answer[i] << " ";
	return 0;
}