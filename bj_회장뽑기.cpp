//#include<vector>
//#include<queue>
//#include<iostream>
//#include<algorithm>
//#include<stack>
//using namespace std;
//vector<int> vec[51];
//vector<int> order;
//deque<pair<int, int>>answer;

//단순 bfs를 통해서 모든 정점에서 정점으로의 최단거리를 구한다.
//int main()
//{
//	int n;
//	int a, b;
//	cin >> n;
//	while (1) {
//		cin >> a >> b;
//		if (a == -1 && b == -1)break;
//		vec[a].push_back(b);
//		vec[b].push_back(a);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		queue<int>q;
//		int cnt = 0;
//		vector<bool>check(n + 1, false);
//		q.push(i);
//		check[i] = true;
//		while (!q.empty()) {
//			cnt++;
//			int size = q.size();
//			for (int i = 0; i < size; i++) {
//				int cur = q.front();
//
//				for (int j = 0; j < vec[cur].size(); j++) {
//					int next = vec[cur][j];
//					if (check[next] == true)continue;
//					check[next] = true;
//					q.push(next);
//				}
//				q.pop();
//			}
//		}
//		if (!answer.empty() && answer.back().first < cnt - 1)continue;
//		while (!answer.empty()&&answer.back().first > cnt - 1)answer.pop_back();
//		answer.push_back({cnt-1,i});
//	}
//	cout << answer.back().first << " " << answer.size() << endl;
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer[i].second;
//		if(i!=answer.size()-1)cout << " ";
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>vec(51, vector<int>(51,10000));
int n, m;
//플로이드 와샬 알고리즘을 통해서 구하자
//답을 구해놓지는 않았다 matrix안에 각각의 정점까지의 거리를 구해놓았다
//이를 통해 회장후보들을 뽑을수 있다.
int main() {
	int n;
	int a, b;
	cin >> n;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1)break;
		vec[a][b] = 1;
		vec[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		vec[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}