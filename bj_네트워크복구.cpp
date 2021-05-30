#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int MAX = 987654321;
int N, M;
vector<int>dist(1001, MAX);
vector<pair<int,int>>vec[1001];
vector<int>path(1001, MAX);
priority_queue<pair<int, int>>pq;


//다익스트라
//다익스트라로 경로를갱신할때 path를 갱신하며 최단거리의 모음을 만든다
/*
<중요한점!!!!>

퍼컴퓨터가 다른 컴퓨터들과 통신하는데 걸리는 최소 시간이, 원래의 네트워크에서 통신하는데 걸리는 최소 시간보다 커져서는 안 된다.

-> 최소 스패닝 트리가 아니라는것을 말해준다.
*/
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});
		vec[b].push_back({ a,c });
	}
	
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int n_cost = vec[cur][i].second+cost ;
			if (dist[next] > n_cost) {
				dist[next] = n_cost;
				pq.push({-n_cost,next});
				path[next] = cur;
			}

		}
	}
	cout << N - 1 << endl;
	for (int i = 2; i <= N ; i++) {
		cout << i << " " << path[i] << endl;
	}
	return 0;
}