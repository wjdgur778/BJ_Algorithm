#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

vector<int>vec_1;
vector<pair<int, int>>vec_2;
int N;
/*N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.
N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.
수의 위치가 다르면 값이 같아도 다른 수이다.*/


//포함한 2개의 합이 아닌 다른수 2개의 합!!!!!!!
//lower 와  upper 사이에 있는 중복값들중 내가 원하는 값을 찾는것이 가장 좋은 방법일까...?
//안에서는 못하나..
// 1. 중복처리를 어떻게 할것인지
// 2. 이후 lower 와 upper 을 어떻게 사용할건데?
// 3. lower사용후 다른순간이 나올때까지 반복을 해도 될거같다. ex) 2번의 binary_search가 아닌 1번의 binary_search를 한 후 target과 달라질때까지 인덱스를 나아간다.
//


//너무 어렵게 푼 감이 없지않다...
//사실 그냥 양쪽에서 조여 들어가면 끝나는 문제;;

bool comp(pair<int, int>a, pair<int, int>b) {
	return vec_1[a.first]+vec_1[a.second] < vec_1[b.first]+vec_1[b.second];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec_1.push_back(a);
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			vec_2.push_back({ i,j }
			);
		}
	}
	sort(vec_2.begin(), vec_2.end(), comp);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int s = 0;
		int e = vec_2.size() - 1;
		bool check = false;
		int target = vec_1[i];
		while (s <= e) {
			int mid = (s + e) / 2;
			int sum = vec_1[vec_2[mid].first] + vec_1[vec_2[mid].second];
			if (target >= sum) {
				s = mid + 1;
				if (target == sum && vec_2[mid].first != i && vec_2[mid].second != i)
					check = true;
			}
			else {
				e = mid - 1;
			}
		}
		s = 0;
		e = vec_2.size() - 1;
		while (s <= e) {
			int mid = (s + e) / 2;
			int sum = vec_1[vec_2[mid].first] + vec_1[vec_2[mid].second];
			if (target > sum) {
				s = mid + 1;
			}
			else {
				if (target == sum && vec_2[mid].first != i && vec_2[mid].second != i)
					check = true;
				e = mid - 1;
			}
		}
		if (check) {
			answer++;
		}
	}
	cout << answer;

	return 0;
}