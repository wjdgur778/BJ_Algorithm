#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int M;
int answer;

vector<vector<int>>vec(51, vector<int>(51, 0));
vector<pair<int, int>>s;
vector < pair<int, pair<int, int>>>dist;
vector<int>check(252, 0);
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
/*세준이는 어느 날 획기적인 로봇을 한 개 개발하였다. 그 로봇은 복제 장치를 이용하면 자기 자신을 똑같은 로봇으로 원하는 개수만큼 복제시킬 수 있다. 세준이는 어느 날 이 로봇을 테스트하기 위하여 어떤 미로에 이 로봇을 풀어 놓았다. 이 로봇의 임무는 미로에 흩어진 열쇠들을 모두 찾는 것이다. 그리고 열쇠가 있는 곳들과 로봇이 출발하는 위치에 로봇이 복제할 수 있는 장치를 장착해 두었다.

N*N의 정사각형 미로와 M개의 흩어진 열쇠의 위치, 그리고 이 로봇의 시작 위치가 주어져 있을 때, 모든 열쇠를 찾으면서 로봇이 움직이는 횟수의 합을 최소로 하는 프로그램을 작성하여라. 로봇은 상하좌우 네 방향으로 움직이며, 로봇이 열쇠가 있는 위치에 도달했을 때 열쇠를 찾은 것으로 한다. (복제된 로봇이어도 상관없다) 하나의 칸에 동시에 여러 개의 로봇이 위치할 수 있으며, 로봇이 한 번 지나간 자리라도 다른 로봇 또는 자기 자신이 다시 지나갈 수 있다. 복제에는 시간이 들지 않으며, 로봇이 움직이는 횟수의 합은 분열된 로봇 각각이 움직인 횟수의 총 합을 말한다. 복제된 로봇이 열쇠를 모두 찾은 후 같은 위치로 모일 필요는 없다.*/

// 최소 스패닝트리
// bfs
// 모든 노드를 이어나가되 최소 비용으로 이어나가야했다.
// 최소 스패닝 트리를 이용해야하는데 이때 가중치 즉 (거리)를 알아야했다.
// bfs를 통해서 각각의 거리를 구하고 sort후 최소 스패닝 트리를 이용해여 풀었다.
// 처음에는 거리를 모두 구해야한다는것에 두려웠다(완탐은 항상 두려운것같음)


int get_p(int n) {
	if (check[n] == n)return n;
	else return check[n] = get_p(check[n]);
}
//거리(가중치 계산)
bool bfs(int start, int x, int y) {
	queue<pair<int, int>>q;
	vector<vector<bool>>visit(51, vector<bool>(51, 0));
	int can = 0;
	q.push({ x,y });
	visit[x][y] = true;

	int level = 0;
	while (!q.empty()) {
		int size = q.size();
		level++;
		for (int j = 0; j < size; j++) {
			int x = q.front().first;
			int y = q.front().second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (vec[nx][ny] == 1)continue;
				if (visit[nx][ny] == true)continue;
				if (vec[nx][ny] >= 2) {
					dist.push_back({ level,{start,vec[nx][ny]} });
					can++;
				}
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
			q.pop();
		}
	}

	if (start == 2) {
		if (can == M)return false;
		else return true;;
	}
	return false;
}

int main() {
	cin >> N >> M;
	int cnt = 3;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			if (a == 'S') {
				vec[i][j] = 2;
				s.push_back({ i,j });
			}
			else if (a == 'K') {
				vec[i][j] = cnt++;
				s.push_back({ i,j });
			}
			else vec[i][j] = a - '0';
		}
	}

	for (int i = 0; i < s.size(); i++) {
		if (bfs(vec[s[i].first][s[i].second], s[i].first, s[i].second)) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 2; i < cnt; i++)check[i] = i;

	sort(dist.begin(), dist.end());

	for (int i = 0; i < dist.size(); i++) {
		int a = get_p(dist[i].second.first);
		int b = get_p(dist[i].second.second);
		int sum = dist[i].first;
		if (a != b) {
			if (check[a] > b)check[a] = b;
			else check[b] = a;
			answer += sum;
		}
	}
	cout << answer;
	return 0;
}
