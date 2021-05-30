#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T;
//��������
//���� �������ķ� ��Ǯ����..
//������ ������ �ݴ�� �޾� �Ųٷ� �Ž��� �ö󰬴ٰ� ������ ���� �޾ƿ��� �������� �ߴ�.

int dfs(int cur, vector<int>vec[]) {

	priority_queue<int>pq;

	if (vec[cur].size() == 0) {
		return 1;
	}

	for (int i = 0; i < vec[cur].size(); i++) {
		int next = vec[cur][i];
		pq.push( dfs(next, vec));
	}

	if (pq.size() == 1)return pq.top();
	else {
		int tmp = pq.top();
		pq.pop();
		if (tmp == pq.top()) {
			return tmp + 1;
		}
		else{
			return tmp;
			}
	}
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int K, M, P;
		vector<int>vec[1001];

		cin >> K >> M >> P;
		//�ݴ�� �̾�
		for (int j = 0; j < P; j++) {
			int a, b;
			cin >> a >> b;
			vec[b].push_back(a);
		}

		cout<<i+1<<" "<< dfs(M,vec)<<'\n';

	}


	return 0;
}