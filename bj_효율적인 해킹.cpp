#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
/*
��Ŀ �������� �� �˷��� ��� ȸ�縦 ��ŷ�Ϸ��� �Ѵ�. �� ȸ��� N���� ��ǻ�ͷ� �̷���� �ִ�. �������� ������ ������, �� ���� ��ŷ���� ���� ���� ��ǻ�͸� ��ŷ �� �� �ִ� ��ǻ�͸� ��ŷ�Ϸ��� �Ѵ�.

�� ȸ���� ��ǻ�ʹ� �ŷ��ϴ� �����, �ŷ����� �ʴ� ����� �̷���� �ִµ�, A�� B�� �ŷ��ϴ� ��쿡�� B�� ��ŷ�ϸ�, A�� ��ŷ�� �� �ִٴ� �Ҹ���.

�� ȸ���� ��ǻ���� �ŷ��ϴ� ���谡 �־����� ��, �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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