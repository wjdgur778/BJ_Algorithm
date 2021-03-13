#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
/*
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.

이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.

이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.
*/
int N;
int M;
vector<int>vec[10001];
int cnt = 0;
int big = 0;
bool Visit[10001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >>M;
	int a, b;
	int ans_c = 0;
	vector<pair<int,int>>answer;
	queue<int>q;

	for (int i = 0; i < M; i++) {
		cin >> b>> a;
		vec[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		 cnt = 0;
		 memset(Visit, false, sizeof(Visit));
		 q.push(i);
		 Visit[i] = true;
		 while (!q.empty()) {
			 int cur = q.front();
			 q.pop();
			 for (int i = 0; i < vec[cur].size(); i++) {
				 if (Visit[vec[cur][i]] == true)continue;
				 q.push({ vec[cur][i] });
				 Visit[vec[cur][i]] = true;
				 cnt++;
			 }
		 }
		 big = cnt >= big ? cnt : big;
		 answer.push_back({ cnt,i });
	}
	for (int i = 0; i < answer.size(); i++) {
		if (big == answer[i].first)cout << answer[i].second << " ";
	}

	return 0;
}