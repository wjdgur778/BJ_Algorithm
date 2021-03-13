#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int m, n, k;
int map[101][101] = { 0 ,};
bool check[101][101] = { false ,};
vector<int>answer;
int area;
int dx[4] = {0,1,0,-1}; // n
int dy[4] = { 1,0,-1,0 }; // m

//´Ü¼ø bfs ¹®Á¦ + ÀÎµ¦½º »ìÂ¦ Çò°¥

void dfs(int x, int y) {
	area++;
	//cout << x << " " << y << endl;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny<0 || nx>n-1 || ny>m-1)continue;
		if (map[nx][ny] == 1 || check[nx][ny] == true)continue;
		check[nx][ny] = true;
		dfs(nx, ny);

	}
	return;
}

int main() {
	cin >> m >> n >> k;
	
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			area = 0;
			if (map[i][j] == 1 || check[i][j] == true)continue;
			check[i][j] = true;
			dfs(i, j);
			answer.push_back(area);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		if (i != answer.size() - 1)cout << answer[i] << " ";
		else cout << answer[i];
	}
	return 0;
}