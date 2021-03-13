#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int INF = 987654321;
vector<vector<int>>vec(101, vector<int>(101, INF));

int n;
int m;

//a to b 다익스트라
//int find(int a, int b) {
//	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//	vector<int>dist(101, 987654321);
//	vector<bool>check(101, false);
//	check[a] = true;
//	pq.push({ 0,a });
//	while (!pq.empty()) {
//
//		int size = pq.size();
//
//		for (int i = 0; i < size; i++) {
//			int cur = pq.top().second;
//			int cost = pq.top().first;
//			if (dist[cur] < cost)continue;
//
//			for (int j = 0; j < vec[cur].size(); j++) {
//				int next = vec[cur][j].first;
//				int n_cost = cost + vec[cur][j].second;
//				if (dist[next] > n_cost) {
//					dist[next] = n_cost;			
//					pq.push({ n_cost,next });
//				}
//				if (cur == b)return dist[cur];
//
//
//			}
//			pq.pop();
//		}
//	}
//	return 0;
//}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		if(vec[a][b]!=INF) vec[a][b] = vec[a][b] < c ? vec[a][b] : c;
		else vec[a][b] = c;
	}
	for (int i = 1; i <= n; i++)vec[i][i] = 0;
	//거쳐가는 점
	for (int k = 1; k <= n; k++) {
		//시작점
		for (int i = 1; i <= n; i++) {
			//마지막점
			for (int j = 1; j <= n; j++) {

				if (vec[i][j] > (vec[i][k] + vec[k][j]))vec[i][j] = vec[i][k] + vec[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		//마지막점
		for (int j = 1; j <= n; j++) {
			if (vec[i][j] == INF)cout << 0;
			else cout << vec[i][j];
			if (j != n)cout << " ";
		}

		cout << endl;
	}

	return 0;
}