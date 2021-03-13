#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V;
int E;
int P;
int INF = 987654321;
/*
������ ����� �׷��� ���·� �Ǿ��ִ�. ������� 1�� ���� ������ V�� �����̴�. ������ 1~V���� �ִ�. �ǿ�� P�� ������ �ִ�.
�׸��� �׻� 1�� �������� P���� V�� �������� �� �� �ִ� ��ΰ� �����Ѵ�.
�ߺ��Ǵ� ������ �ڱ� �ڽ��� ����Ű�� ������ �������� �ʴ´�.1��3��4��5��6 �Ǵ� 1��3��5��6 �̴�. �̰� �߿��� �ǿ찡 �ִ� ��, �� 4�� ������ ���Ե� �ִ� ��ΰ� �����Ƿ� �� ��쿡�� �����̰� �ǿ츦 ���� �� �ִ�.

�����̰� �ǿ츦 �����ִ� ����� ���̰� �ִ� ����� ���̺��� ������� �ʴ´ٸ�, �����̴� �ݵ�� �ǿ츦 �����ַ� ����.
*/

//���ͽ�Ʈ��
//���ͽ�Ʈ�� ��� �����Ұ��̳�
//

//SAVE HIM, GOOD BYE //
vector<pair<int, int>>vec[10001];
int solution(int s,int e) {
	vector<int> dist(V + 1, INF);
	priority_queue<pair<int, int>> pq;

	dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {

		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == e) {
			break;
		}
		if (cost > dist[cur]) {
			continue;
		}

		for (int j = 0; j < vec[cur].size(); j++) {
			int n_c = cost + vec[cur][j].first;
			int next = vec[cur][j].second;
			if (dist[next] > n_c) {
				//cout << next << endl;
				pq.push({ -n_c,next });
				dist[next] = n_c;
			}
		}
	}
	return dist[e];
}


int main() {
	cin >> V >> E >> P;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	if (P == 1) {
		cout << "SAVE HIM";
		return 0;
	}

	//�ٽ�
	//�߰��� �ִ� ģ���� ������ �������� ���� ���� �ٷ� �������� ���� ����� ������ �������� �� �ִ�.
	if (solution(1,V) == solution(1,P)+solution(P,V) ){
		cout << "SAVE HIM";
	}
	else {
		cout << "GOOD BYE";
	}


	return 0;
}