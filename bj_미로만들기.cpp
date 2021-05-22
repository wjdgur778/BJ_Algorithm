#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int vec[51][51];
int dist[51][51];
bool check[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
priority_queue<pair<int, pair<int, int>>>pq;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			vec[i][j] = a - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
			if (vec[i][j] == 1)dist[i][j] = 0;
			else dist[i][j] = 1;
		}
	}
	pq.push({ -0, { 0,0 } });
	check[0][0] = true;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		pair<int, int>cord = pq.top().second;
		cout << "x : " << cord.first << " " << "y : " << cord.second << " cost : " << cost << endl;
		pq.pop();
		//if (dist[cord.first][cord.second] < cost)continue;
		if (cord.first == N - 1 && cord.second == N - 1) {
			cout << cost;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cord.first + dx[i];
			int ny = cord.second + dy[i];
			int n_cost = cost + dist[nx][ny];
			if (nx < 0 || ny < 0 || nx>N - 1 || ny>N - 1)continue;
			if (check[nx][ny] == true)continue;

			pq.push({ -n_cost,{nx,ny} });
			check[nx][ny] = true;


		}

	}

	return 0;
}