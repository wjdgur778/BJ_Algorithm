#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MAX = 1000000;
int N;
int K;
int D;
vector<pair<int,pair<int,int>>> vec;

int main()
{
	cin >> N >> K >> D;
	int a,b,c;
	int answer = 0;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c;
		vec.push_back({ a,{b,c} });
	}
	sort(vec.begin(), vec.end());
	int s = vec[0].first;
	int e = MAX;
	int target = D;
	while (s <= e) {
		int mid = (s + e) / 2;
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first > mid)break;

			if (vec[i].second.first < mid) {
				sum +=( (vec[i].second.first - vec[i].first) / vec[i].second.second ) + 1;
			}
			else {
				sum +=( (mid - vec[i].first) / vec[i].second.second )+ 1;
			}
		}
		if (target <= sum) {
			e = mid - 1;
			answer = mid;
		}
		else {
			s = mid + 1;
		}

	}
	cout << answer;

	return 0;
}