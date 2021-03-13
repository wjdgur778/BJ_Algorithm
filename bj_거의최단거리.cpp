#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int N;
int M;
int s;
int d;
//s to d ���� �ִܰŸ� ��θ� ������ �ִܰŸ��� ���ض�~?
//���ͽ�Ʈ��?
//���ͽ�Ʈ��� �ִܰŸ��� ���Ҽ� �־ �ִ� ��θ�?? ���ϱ� �����


/*
������ Ǯ����鼭 ���հ��������� ȭ���� ����;;
���ͽ�Ʈ�� => ��� ���� => ���ͽ�Ʈ�� ������ ������ Ǯ����� �ȴ�.
��������!!!!!!!!!!!
1. �׽�Ʈ ���̽��� �ݺ��� �����Ƿ� �����Ҷ� �׻� �����Ұ�
2. �׻� �������� ����ġ�� 0...
3. ���ͽ�Ʈ�� �̿��ؼ� �ּҰ�θ� ã�Ƴ����� ���� ������ �׻� ����ؾ��Ѵ�.
   ���������� q���� ���� �ʵ� , ��θ� �˾ƺ������� ��δ� �������(���� ���� �ּҰ�ΰ� �������̱� ����)
4. ������ ��ġ��
5. �Ա� ������ �ʿ䰡 �ʹ� ����;;
*/

int INF = 987654321;
vector<vector<bool>>check;
void bfs(vector<pair<int, int>>path[], vector<int>dist, vector<pair<int, int>>vec[]) {
	//	cout <<"dist : "<< dist[d] << endl;
	queue<int>q;
	q.push(d);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == s)continue;

		for (int j = 0; j < path[cur].size(); j++) {
			int pre = path[cur][j].first;
			int cost = path[cur][j].second;
			//�̰� ��??
			//üũ�س����� �������� Ư������ �ʴ� �� �ߺ� üũ�� ������!!!
			if (check[pre][cur] == true)continue;

			//����Ʈ!! ����� ��θ� Ȯ���ϸ鼭 ����� ��ΰ� �ִܰ�ζ�� check�� ǥ��!

			if (dist[pre] + cost == dist[cur]) {
				//cout<< "pre : " << pre << " cur : " << cur << endl;
				check[pre][cur] = true;
				q.push(pre);
			}
		}
	}
	return;
}


int main() {
	while (true) {
		vector<pair<int, int>>vec[501];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int>dist(501, INF);
		vector<pair<int, int>>path[501];
		vector<vector<bool>>tmp(501, vector<bool>(501, false));
		check = tmp;
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		cin >> s >> d;

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vec[a].push_back({ b,c });
		}
		dist[s] = 0;
		pq.push({ 0,s });

		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (cost > dist[cur])continue;;
			for (int i = 0; i < vec[cur].size(); i++) {
				int next = vec[cur][i].first;
				int n_c = cost + vec[cur][i].second;

				if (dist[next] > n_c) {
					dist[next] = n_c;
					path[next].push_back({ cur,vec[cur][i].second });
					pq.push({ n_c,next });
				}
				else if (dist[next] == n_c) {
					path[next].push_back({ cur,vec[cur][i].second });
				}
			}
		}

		bfs(path, dist, vec);

		vector<int>o_dist(501, INF);
		pq.push({ 0,s });
		o_dist[s] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (cost > o_dist[cur])continue;
			for (int i = 0; i < vec[cur].size(); i++) {
				int next = vec[cur][i].first;
				int n_c = cost + vec[cur][i].second;
				if (check[cur][next])continue;

				if (o_dist[next] > n_c) {
					o_dist[next] = n_c;
					pq.push({ n_c,next });
				}
			}
		}

		int answer = o_dist[d] == INF ? -1 : o_dist[d];
		cout << answer << '\n';
	}
	return 0;
}