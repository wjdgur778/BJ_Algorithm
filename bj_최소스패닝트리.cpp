#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v;
int e;
vector < pair<int, pair<int, int>>>vec;
vector <int> check(10001, 0);
int answer = 0;

int get_p(int a) {
	if (a == check[a]) return a;
	return check[a] = get_p(check[a]);
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}

	//한줄한줄 중요한것같습니다.
	for (int i = 1; i <= v; i++)check[i] = i;
	//오름차순 소팅
	sort(vec.begin(), vec.end());

	//부모를 찾아 부모가 같으면 스킵
	for (int i = 0; i < e; i++) {
		int a = get_p(vec[i].second.first);
		int b = get_p(vec[i].second.second);
		int c = vec[i].first;
		if (a !=b) {
			if (a < b)check[b] = a;
			else check[a] = b;
			answer += c;
		}
	}
	cout << answer;
	return 0;
}