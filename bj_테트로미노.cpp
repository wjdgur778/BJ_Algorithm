#include<iostream>
#include<vector>
using namespace std;
//즉 4개의 경로를 갔을때 합이 최대인 구간을 찾자? 정도로 되려나
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int vec[501][501];
bool check[501][501];
int answer = 0;
int N, M;

void dfs(int x, int y, int cnt, int sum) {

	if (cnt == 4) {
		//cout << answer << endl;
		answer = answer <= sum ? sum : answer;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check[nx][ny] == true)continue;
			if (nx < 0 || ny < 0 || nx>N - 1 || ny>M - 1) continue;
			check[nx][ny] = true;
			dfs(nx, ny, cnt + 1, sum + vec[nx][ny]);
			check[nx][ny] = false;
		}
	}
	return;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			vec[i][j] = a;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = true;
			dfs(i, j, 1, vec[i][j]);
			check[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M-2; j++) {
			int sum = 0;
			if (i == 0) sum+=vec[i][j] + vec[i][j+1] + vec[i][j+2]+vec[i+1][j+1];
			else if (i==N-1) sum += vec[i][j] + vec[i][j + 1] + vec[i][j + 2] + vec[i - 1][j + 1];
			else {
				sum += vec[i][j] + vec[i][j + 1] + vec[i][j + 2];
				sum+= vec[i + 1][j + 1]<=vec[i-1][j+1 ]? vec[i - 1][j + 1]: vec[i + 1][j + 1];
			}
			answer = answer <= sum ? sum : answer;
		}
	}
	for (int j = 0;j < M; j++) {
		for (int i = 0; i < N - 2; i++) {
			int sum = 0;
			if (j == 0) sum += vec[i][j] + vec[i+1][j] + vec[i+2][j] + vec[i+1][j+1];
			else if (j == M - 1) sum += vec[i][j] + vec[i][j + 1] + vec[i][j + 1] + vec[i + 1][j - 1];
			else {
				sum += vec[i][j] + vec[i+1][j] + vec[i+2][j];
				sum += vec[i + 1][j + 1] <= vec[i + 1][j - 1] ? vec[i + 1][j - 1] : vec[i + 1][j + 1];
			}
			answer = answer <= sum ? sum : answer;
		}
	}
	cout << answer;
	return 0;
}