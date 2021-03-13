#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int vec[30][30] = {0,};
bool check[30][30] = { 0, };

int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int cnt = 0;
void dfs(int x, int y) {
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) continue;
		if (vec[nx][ny] == 1&& check[nx][ny]==false) {
			check[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}
int main() {
	vector<int>answer;
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			vec[i][j] = a - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vec[i][j] == 1 && check[i][j] == false) {
				cnt = 0;
				check[i][j] = true;
				dfs(i, j);
				answer.push_back(cnt);
			}
		}
	}
	cout << answer.size() << endl;;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)cout << answer[i] << endl;
	return 0;
}