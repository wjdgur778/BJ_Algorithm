#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = {1,0,-1,0};
bool f = true;

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char a;
			cin >> a;
			map[i][j] = a-'0';
		}
	}
	for (int i = 0; i < M; i++) {
		
		if (!f)break;
		if (map[0][i] == 0) {
			queue<pair<int, int>>q;
			vector<vector<bool>>check(1001, vector<bool>(1001, false));
			q.push({ 0,i });
			check[0][i] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				cout << x << " " << y << endl;
				if (x == N - 1) {
					f = false;
					cout << "YES";
					break;
				}
				q.pop();
				for (int j= 0;j < 4; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];
					if (nx > N - 1 || ny > M - 1 || nx < 0 || ny < 0) continue;
					if (check[nx][ny] == true)continue;
					if (map[nx][ny] == 1)continue;
					q.push({nx,ny});
					check[nx][ny] = true;
				}
			}
		}
	}
	if (f)cout << "NO";
	return 0;
}