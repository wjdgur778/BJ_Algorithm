#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T;
//위상정렬
//나는 위상정렬로 안풀었다..
//방향을 완전히 반대로 받아 거꾸로 거슬러 올라갔다가 끝에서 값을 받아오는 형식으로 했다.

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
		//반대로 이어
		for (int j = 0; j < P; j++) {
			int a, b;
			cin >> a >> b;
			vec[b].push_back(a);
		}

		cout<<i+1<<" "<< dfs(M,vec)<<'\n';

	}


	return 0;
}