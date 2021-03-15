#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int C;
vector<int>vec;
int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	int s = 0;
	int e = 2000000000;
	int answer = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 1;
		int idx = 0;

		for (int i = 1; i < vec.size() ; i++) {
			if (vec[i] - vec[idx] >= mid) {
				idx = i;
				cnt++;
			}
		}
		if (cnt >= C) {
			s = mid + 1;
			answer = answer <= mid ? mid : answer;
		}
		else {
			e = mid - 1;
		}
	}
	cout << answer;
	return 0;
}