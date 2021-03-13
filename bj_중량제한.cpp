#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//int INF = 1000000000;
vector<pair<int, int>>bridge[10001];
//vector<int>dist(10001, INF);
//vector<bool>check(10001, 0);
//queue<int>q;
int n;
int m;
int s;
int e;
//int answer = 0;
////경로상의 최소값이 가장 큰 경로를 골라라
////dfs는 시간초과!!!!!!!!!!!!!! (시부레꺼)
////
//
//void dfs(int n,int cost) {
//	//cout << n << endl;
//	if (n == e)return;
//	for (int i = 0; i < bridge[n].size(); i++) {
//		if (check[bridge[n][i].first ] == true)continue;
//		answer = answer > bridge[n][i].second ? bridge[n][i].second : answer;
//		check[bridge[n][i].first] = true;
//		dfs(bridge[n][i].first,bridge[n][i].second);
//		check[bridge[n][i].first] = false;
//	}
//
//}
//int main() {
//	cin >> n;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		int a;
//		int b;
//		int c;
//		cin >> a >> b>>c;
//		bridge[a].push_back({ b,c });
//		bridge[b].push_back({ a,c });
//	}
//	cin >> s;
//	cin >> e;
//	dfs(s, 0);
//	cout << answer;
//	//for (int i = 0; i < 4; i++)cout << dist[i] << " ";
//	return 0;
//}
//

//단순 bfs 시도
//왜틀린지 정확히 분석해 봐야함/ 최소 경로중 최대라는 원리를 사용하는거 자체가 틀렸나...
//

//int main() {
//	cin >> n;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		int a;
//		int b;
//		int c;
//		cin >> a >> b >> c;
//		bridge[a].push_back({ b,c });
//		bridge[b].push_back({ a,c });
//	}
//	cin >> s;
//	cin >> e;
//	q.push(s);
//	while (!q.empty()) {
//		int size = q.size();
//
//		for (int i = 0; i < size; i++) {
//			int cur = q.front();
//			check[cur] = true;
//			//cout << cur << " ";
//			for (int j = 0; j < bridge[cur].size(); j++) {
//				int cost = bridge[cur][j].second;
//				int next = bridge[cur][j].first;
//				if (check[next] == true)continue;
//
//				if (dist[cur] > cost)dist[next] = cost;
//				else dist[next] = dist[cur];
//
//				if (next == e) {
//					answer = answer > dist[next] ? answer : dist[next];
//					check[e] = false;
//				}
//				q.push(next);
//			}
//			q.pop();
//		}
//
//	}
//	cout << answer;
//	//for (int i = 0; i < 4; i++)cout << dist[i] << " ";
//	return 0;
//}


//도달하면 true, 도달하지 못하면 false
bool bfs(int n, int weight) {
	vector<bool>check(10001, 0);
	queue<int>q;
	check[s] = true;
	q.push(n);
	while (!q.empty()) {

		int size = q.size();
		for (int i = 0; i < size; i++) {
			int cur = q.front();
			if (cur == e)return true;

			for (int j = 0; j < bridge[cur].size(); j++) {
				int cost = bridge[cur][j].second;
				int next = bridge[cur][j].first;
				//여기서 헷갈렸다.
				//당연히 cost가 크면 넘기는거 아닌가?
				//하지만 weight가 정답인지 아닌지를 구분하기 위한 bfs => 즉 weight가 cost보다 항상작아야 그 weight는 정답이 될수 있다.
				if (cost < weight)continue;
				if (check[next] == true)continue;
				check[next] = true;
				q.push(next);
			}
			q.pop();
		}
	}
	return false;
}
int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		bridge[a].push_back({ b,c });
		bridge[b].push_back({ a,c });
	}
	cin >> s;
	cin >> e;
	int s_w = 1;
	int e_w = 1000000000;
	int answer = 1000000000;

	//시작지점부터 도착지점까지 도달할수있는 중량을 이분탐색으로 찾아가며
	//bfs를 통해 확인한다.

	while (s_w <= e_w) {
		int mid = (s_w + e_w) / 2;

		cout << "sw :  " << s_w << " ew : " << e_w << " mid : " << mid << " answer : " << answer << endl;
		if (bfs(s, mid)) {
			s_w = mid + 1;
			answer = mid;
		}
		else {
			e_w = mid - 1;
		}
	}
	cout << answer;
	return 0;
}

/*
3 3
1 2 100
3 1 99
1 2 100
1 3
*/