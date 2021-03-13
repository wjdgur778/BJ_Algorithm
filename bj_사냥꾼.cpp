#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>vec;
vector<pair<int,int>>animal;

int m;
int n;
int l;

int count(int i, int a, int b) {
	if (b < 0) {
		if (abs(vec[a] - animal[i].first) + animal[i].second <= l)return 1;
	}
	else {
		if (abs(vec[a] - animal[i].first) + animal[i].second <= l || abs(vec[b] - animal[i].first) + animal[i].second <= l)return 1;
	}
}

int main() {
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++) {
		int a; 
		cin >> a;
		vec.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		int b;
		cin >> a >> b;
		animal.push_back({a,b});
	}
	sort(vec.begin(), vec.end());
	int answer = 0;
	for (int i = 0; i < animal.size(); i++) {
		int s = 0;
		int e = vec.size()-1;
		cout << "i : " << i << " ";
		while (s <= e) {
			int mid = (s + e) / 2;
			if (vec[mid] < animal[i].first) {
				s = mid + 1;

			}
			else {
				e = mid - 1;
			}
		}
		cout << s << " " << e << endl;;
		answer += count(i, s, e);
	}
	cout << answer;
	return 0;
}