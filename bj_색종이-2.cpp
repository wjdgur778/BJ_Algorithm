#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
vector<pair<int, int>>vec;
vector<vector<int>> map(1002, vector<int>(1002, 0));
vector<vector<bool>>check(1002, vector<bool>(1002, 0));
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int bfs(int i, int j) {
	queue<pair<int, int>>q;
	int sum = 0;
	q.push({ i,j });
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (map[nx][ny] == 0)sum++;
				else if (map[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			q.pop();
		}
	}
	return sum;
}
int main() {
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int jj = b; jj < b + 10; jj++) {
				map[j][jj] = 1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (check[i][j] == false&&map[i][j]==1) {
				check[i][j] = true;
				result+=	bfs(i, j);
			}
		}

	}
	cout << result;
	return 0;
}