#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, k;
		long long sum = 0;
		vector<int>vec;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			vec.push_back(a);
		}
		//logic
		//서로 다른 두개의 정수의 합이 k에 가장 가깝게 하는 두정수를 구해
		// MAX : 1000000
		// 수행하면서 최소였던 친구들을 모아라
		//투포인터??
		// 4
		//-7 -4 -3 -2 0 1 2 5 9 12
		//1 3 5 7 9
		// 비교 기준을 정하자
		int s = 0;
		int e = vec.size() - 1;
		int target = k;
		long long comp = 9876542311;
		sort(vec.begin(), vec.end());
		int cnt = 0;
		while (s < e) {
			if (k > vec[s] + vec[e]) {
				//최소면 갱신
				s++;
			}
			else if (k == vec[s] + vec[e]) {
				s++;
				cnt++;
				e--;
			}
			else e--;
		}

		cout << cnt << "\n";

	}
	return 0;
}