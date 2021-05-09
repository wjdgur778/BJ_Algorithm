#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
/*
N��M�� �迭���� ����� ã������ �Ѵ�. �迭�� �� ĭ���� 0�� 1 ���� �ϳ��� ����ִ�. �� ĭ�� ���� ���� �����Ҷ�, �� ĭ�� �����ϴٰ� �Ѵ�.

1�� ��� �ִ� ������ ĭ���� �������� ��, ������ ���� ��Ҹ� ����̶�� �θ���. ����� ũ��� ��翡 ���ԵǾ� �ִ� 1�� �����̴�.

�迭�� ĭ �ϳ��� ����ִ� ���� �����ؼ� ���� �� �ִ� ����� �ִ� ũ�⸦ ���غ���.*/

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
	//�̸� �׷�ȭ�ϱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vec[i][j] == 1 && check[i][j] == false) {
				region[cnt++] = bfs(i, j);
			}
		}
	}
	//�̸� �׷�ȭ�� ������ �������� �̿��� �������� �ִ븦 ���Ѵ�.
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