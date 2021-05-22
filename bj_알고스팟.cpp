#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int M;
vector<vector<int>> vec(101, vector<int>(101, 0));
vector<vector<int>>dist;
vector<vector<bool>> check(101, vector<bool>(101, false));

int dx[4] = { 0,1,-1,0};
int dy[4] = {1,0,0,-1};
priority_queue < pair<int, pair<int, int>>> pq;
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char a;
			cin >> a;
			vec[i][j] = a - '0';
		}
	}
	dist = vec;
	pq.push({ -0, { 0,0 } });
	check[0][0] = true;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		pair<int, int>cord = pq.top().second;

		pq.pop();
		//if (dist[cord.first][cord.second] < cost)continue;
		if (cord.first == N - 1 && cord.second == M - 1) {
			cout << cost;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cord.first + dx[i];
			int ny = cord.second + dy[i];
			int n_cost = cost + dist[nx][ny];
			if (nx < 0 || ny < 0 || nx>N - 1 || ny>M - 1)continue;
			if (check[nx][ny] == true)continue;

			pq.push({ -n_cost,{nx,ny} });
			check[nx][ny] = true;
		}
	}
	return 0;
}