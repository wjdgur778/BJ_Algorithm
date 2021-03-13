#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int n, m,a;
vector<vector<int>>vec(100, vector<int>(100, 0));
vector<vector<bool>>check(100, vector<bool>(100, 0));
queue<pair<int,int>>q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int level = 0;

void bfs() {
	q.push({ 0,0 });
	check[0][0] = true;
	while (!q.empty()) {
		int size = q.size();
		level++;
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == n - 1 && y == m - 1)return;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
				if (vec[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			q.pop();
		}

	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			vec[i][j] = a- '0';
		}
	}
	bfs();
	cout << level ;
	return 0;
}
