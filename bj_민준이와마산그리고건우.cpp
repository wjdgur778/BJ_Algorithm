#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V;
int E;
int P;
int INF = 987654321;
/*
지도는 양방향 그래프 형태로 되어있다. 출발지는 1번 정점 마산은 V번 정점이다. 정점은 1~V까지 있다. 건우는 P번 정점에 있다.
그리고 항상 1번 정점에서 P번과 V번 정점으로 갈 수 있는 경로가 존재한다.
중복되는 간선과 자기 자신을 가리키는 간선은 존재하지 않는다.1→3→4→5→6 또는 1→3→5→6 이다. 이것 중에서 건우가 있는 곳, 즉 4번 정점이 포함된 최단 경로가 있으므로 이 경우에는 민준이가 건우를 도울 수 있다.

민준이가 건우를 도와주는 경로의 길이가 최단 경로의 길이보다 길어지지 않는다면, 민준이는 반드시 건우를 도와주러 간다.
*/

//다익스트라
//다익스트라를 어떻게 적용할것이냐
//

//SAVE HIM, GOOD BYE //
vector<pair<int, int>>vec[10001];
int solution(int s,int e) {
	vector<int> dist(V + 1, INF);
	priority_queue<pair<int, int>> pq;

	dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {

		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == e) {
			break;
		}
		if (cost > dist[cur]) {
			continue;
		}

		for (int j = 0; j < vec[cur].size(); j++) {
			int n_c = cost + vec[cur][j].first;
			int next = vec[cur][j].second;
			if (dist[next] > n_c) {
				//cout << next << endl;
				pq.push({ -n_c,next });
				dist[next] = n_c;
			}
		}
	}
	return dist[e];
}


int main() {
	cin >> V >> E >> P;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	if (P == 1) {
		cout << "SAVE HIM";
		return 0;
	}

	//핵심
	//중간에 있는 친구를 데리고 목적지에 가는 비용과 바로 목적지로 가는 비용이 같으면 데리러갈 수 있다.
	if (solution(1,V) == solution(1,P)+solution(P,V) ){
		cout << "SAVE HIM";
	}
	else {
		cout << "GOOD BYE";
	}


	return 0;
}