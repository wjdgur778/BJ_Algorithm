#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n;
int m;
vector<int>graph[32005];
int vec[32005] = { 0, };
priority_queue<int, vector<int>, greater<int>>p_q;

//위상정렬

int main() {
	cin >> n >> m;
	//진입 차수 늘려주기
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		vec[b] ++;
	}
	//진입 차수가 0인 친구들 큐에 넣어 시작
	//진입 차수가 0인 친구들이 먼저 시작되어야 함
	for (int i = 1; i <= n; i++) {
		if (vec[i] == 0) p_q.push(i);
	}
	//위상정렬을 하되
	//우선순위큐를 이용하여 가장 낮은순으로 출력

	while (!p_q.empty()) {
		int cur = p_q.top();
		cout << cur<<" ";
		p_q.pop();
		for (int next : graph[cur]) {
			vec[next]--;
			if (!vec[next])p_q.push(next);
		}
	}

	return 0;
}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include<iostream>
//#include <queue>
//
//using namespace std;
//int in[32004], N, M, a, b;
//vector<int> adj[32004];
//priority_queue<int, vector<int>, greater<int>> q;
//int main() {
//    cin >> N>> M;
//    for (int i = 0; i < M; i++) {
//        int a, b;
//        cin >> a >> b;
//        adj[a].push_back(b);
//        in[b]++;
//    }
//    for (int i = 1; i <= N; i++)if (!in[i]) q.push(i);
//    while (q.size()) {
//        int here = q.top(); q.pop();
//        printf("%d ", here);
//        for (int there : adj[here]) {
//            in[there]--;
//            if (!in[there])q.push(there);
//        }
//    }
//    return 0;
//}