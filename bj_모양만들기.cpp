#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
/*
N×M인 배열에서 모양을 찾으려고 한다. 배열의 각 칸에는 0과 1 중의 하나가 들어있다. 두 칸이 서로 변을 공유할때, 두 칸을 인접하다고 한다.

1이 들어 있는 인접한 칸끼리 연결했을 때, 각각의 연결 요소를 모양이라고 부르자. 모양의 크기는 모양에 포함되어 있는 1의 개수이다.

배열의 칸 하나에 들어있는 수를 변경해서 만들 수 있는 모양의 최대 크기를 구해보자.*/

int N, M;
int vec[1001][1001];
bool check[1001][1001];
int answer = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int region[1000001];
int cnt = 2;
int bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	check[x][y] = true;
	int count = 1;
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		vec[cur.first][cur.second] = cnt;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1)continue;
			if (check[nx][ny] == true || vec[nx][ny] == 0)continue;
			q.push({ nx,ny });
			check[nx][ny] = true;
			count++;
		}
	}
	return count;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> vec[i][j];
		}
	}
	//미리 그룹화하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vec[i][j] == 1 && check[i][j] == false) {
				region[cnt++] = bfs(i, j);
			}
		}
	}
	//미리 그룹화한 정보를 바탕으로 이웃한 정보들의 최대를 구한다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vec[i][j] == 0) {
				set<int>s;
				int tmp = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1)continue;
					if (vec[nx][ny] == 1)continue;
					if (s.find(vec[nx][ny]) != s.end())continue;
					s.insert(vec[nx][ny]);
					tmp += region[vec[nx][ny]];
				}
				answer = tmp +1>= answer ? (tmp + 1) : answer;
			}
		}
	}
	cout << answer;


	return 0;
}