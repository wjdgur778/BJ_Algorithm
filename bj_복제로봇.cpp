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
/*�����̴� ��� �� ȹ������ �κ��� �� �� �����Ͽ���. �� �κ��� ���� ��ġ�� �̿��ϸ� �ڱ� �ڽ��� �Ȱ��� �κ����� ���ϴ� ������ŭ ������ų �� �ִ�. �����̴� ��� �� �� �κ��� �׽�Ʈ�ϱ� ���Ͽ� � �̷ο� �� �κ��� Ǯ�� ���Ҵ�. �� �κ��� �ӹ��� �̷ο� ����� ������� ��� ã�� ���̴�. �׸��� ���谡 �ִ� ����� �κ��� ����ϴ� ��ġ�� �κ��� ������ �� �ִ� ��ġ�� ������ �ξ���.

N*N�� ���簢�� �̷ο� M���� ����� ������ ��ġ, �׸��� �� �κ��� ���� ��ġ�� �־��� ���� ��, ��� ���踦 ã���鼭 �κ��� �����̴� Ƚ���� ���� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͽ���. �κ��� �����¿� �� �������� �����̸�, �κ��� ���谡 �ִ� ��ġ�� �������� �� ���踦 ã�� ������ �Ѵ�. (������ �κ��̾ �������) �ϳ��� ĭ�� ���ÿ� ���� ���� �κ��� ��ġ�� �� ������, �κ��� �� �� ������ �ڸ��� �ٸ� �κ� �Ǵ� �ڱ� �ڽ��� �ٽ� ������ �� �ִ�. �������� �ð��� ���� ������, �κ��� �����̴� Ƚ���� ���� �п��� �κ� ������ ������ Ƚ���� �� ���� ���Ѵ�. ������ �κ��� ���踦 ��� ã�� �� ���� ��ġ�� ���� �ʿ�� ����.*/

// �ּ� ���д�Ʈ��
// bfs
// ��� ��带 �̾���� �ּ� ������� �̾�����ߴ�.
// �ּ� ���д� Ʈ���� �̿��ؾ��ϴµ� �̶� ����ġ �� (�Ÿ�)�� �˾ƾ��ߴ�.
// bfs�� ���ؼ� ������ �Ÿ��� ���ϰ� sort�� �ּ� ���д� Ʈ���� �̿��ؿ� Ǯ����.
// ó������ �Ÿ��� ��� ���ؾ��Ѵٴ°Ϳ� �η�����(��Ž�� �׻� �η���Ͱ���)


int get_p(int n) {
	if (check[n] == n)return n;
	else return check[n] = get_p(check[n]);
}
//�Ÿ�(����ġ ���)
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
