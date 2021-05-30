#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int MAX = 987654321;
int N, M;
int A, B, K, G;
vector<int>dist(1001, MAX);
int INF = 987654321;

vector<pair<int, int>>vec[1001];
priority_queue<pair<int, int>>pq;
vector<int>visit;
pair<int, int> nono[1001][1001];
int info[1001][1001];

//다익스트라
//다익스트라를 사용하되 중간중간 정보들이 많다(조건들)
//미리 자료구조를 만드는것에 두려워하지 말것
//방향성을 잘 알아두자
//다익스트라 틀을 잘 알아두고 너무 구체적으로 빠져들어가기보다 전체를 바라보자

int main() {
	cin >> N >> M;
	cin >> A >> B >> K >> G;
	for (int i = 0; i < G; i++) {
		int a;
		cin >> a;
		visit.push_back(a);
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
		info[a][b] = c;
		info[b][a] = c;
	}
	int sum = 0;
	for (int i = 0; i < G - 1; i++) {
		nono[visit[i]][visit[i + 1]].first = sum;
		nono[visit[i+1]][visit[i]].first = sum;

		sum += info[visit[i]][visit[i + 1]];
		nono[visit[i]][visit[i + 1]].second = sum;
		nono[visit[i+1]][visit[i]].second= sum;

	}
	for (int i = 1; i <= N; i++)dist[i] = INF;
	//for (int i = 0; i < M+1; i++) {
	//	for (int j = 0; j < M+1; j++) {
	//		cout <<i<<" "<<j<<" "<< nono[i][j].first << " "<<nono[i][j].second<<endl;

	//	}cout << endl;
	//}

	pq.push({ (-1) * K,A });
	dist[A] = K;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int n_cost = vec[cur][i].second;

			if (nono[cur][next].first <= dist[cur] && nono[cur][next].second > dist[cur]) {
				n_cost += nono[cur][next].second - cost;
			}
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next],next });
			}
		}
	}
	//for (int i = 1; i <= N; i++)cout<<dist[i]<<" ";
	cout << dist[B] - K;
	return 0;
}