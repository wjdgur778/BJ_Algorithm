#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int N;
int M;
vector<int>vec;
vector<vector<int>> answer;
set<int> just_c;
vector<int> s;

/*N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.*/


//일반 순열을 묻고있다.
//하지만 모두를 백터에 넣고 프린트를 한다면 엄청난 부하가 걸림
// M개를 뽑았을때 마다 출력을 하는 식으로 해보자

void dfs(int cnt) {
	if (cnt == M) {//중복 되면
		for (int i = 0; i < s.size(); i++)cout << s[i] << " ";
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		s.push_back(vec[i]);
		dfs(cnt + 1);
		s.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (just_c.find(a) == just_c.end()) {
			just_c.insert(a);
			vec.push_back(a);
		}
	}
	sort(vec.begin(), vec.end());
	dfs(0);

	return 0;
}