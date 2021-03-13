#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int N;
int M;
int s;
int d;
//s to d 로의 최단거리 경로를 제외한 최단거리를 구해라~?
//다익스트라?
//다익스트라로 최단거리는 구할수 있어도 최단 경로를?? 구하기 힘들다


/*
문제를 풀어오면서 열손가락안으로 화가난 문제;;
다익스트라 => 경로 제거 => 다익스트라 순으로 문제를 풀어나가면 된다.
주의할점!!!!!!!!!!!
1. 테스트 케이스의 반복이 있으므로 선언할때 항상 주의할것
2. 항상 시작점의 가중치는 0...
3. 다익스트라를 이용해서 최소경로를 찾아나갈때 같은 순간도 항상 고려해야한다.
   같을때에는 q에는 넣지 않되 , 경로를 알아보기위해 경로는 기록하자(여러 개의 최소경로가 있을것이기 때문)
4. 아직도 빡치네
5. 함깨 상의할 필요가 너무 있음;;
*/

int INF = 987654321;
vector<vector<bool>>check;
void bfs(vector<pair<int, int>>path[], vector<int>dist, vector<pair<int, int>>vec[]) {
	//	cout <<"dist : "<< dist[d] << endl;
	queue<int>q;
	q.push(d);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == s)continue;

		for (int j = 0; j < path[cur].size(); j++) {
			int pre = path[cur][j].first;
			int cost = path[cur][j].second;
			//이거 왜??
			//체크해나가는 문제에서 특별하지 않는 한 중복 체크는 피하자!!!
			if (check[pre][cur] == true)continue;

			//포인트!! 기록한 경로를 확인하면서 기록한 경로가 최단경로라면 check에 표시!

			if (dist[pre] + cost == dist[cur]) {
				//cout<< "pre : " << pre << " cur : " << cur << endl;
				check[pre][cur] = true;
				q.push(pre);
			}
		}
	}
	return;
}


int main() {
	while (true) {
		vector<pair<int, int>>vec[501];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int>dist(501, INF);
		vector<pair<int, int>>path[501];
		vector<vector<bool>>tmp(501, vector<bool>(501, false));
		check = tmp;
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		cin >> s >> d;

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vec[a].push_back({ b,c });
		}
		dist[s] = 0;
		pq.push({ 0,s });

		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (cost > dist[cur])continue;;
			for (int i = 0; i < vec[cur].size(); i++) {
				int next = vec[cur][i].first;
				int n_c = cost + vec[cur][i].second;

				if (dist[next] > n_c) {
					dist[next] = n_c;
					path[next].push_back({ cur,vec[cur][i].second });
					pq.push({ n_c,next });
				}
				else if (dist[next] == n_c) {
					path[next].push_back({ cur,vec[cur][i].second });
				}
			}
		}

		bfs(path, dist, vec);

		vector<int>o_dist(501, INF);
		pq.push({ 0,s });
		o_dist[s] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (cost > o_dist[cur])continue;
			for (int i = 0; i < vec[cur].size(); i++) {
				int next = vec[cur][i].first;
				int n_c = cost + vec[cur][i].second;
				if (check[cur][next])continue;

				if (o_dist[next] > n_c) {
					o_dist[next] = n_c;
					pq.push({ n_c,next });
				}
			}
		}

		int answer = o_dist[d] == INF ? -1 : o_dist[d];
		cout << answer << '\n';
	}
	return 0;
}