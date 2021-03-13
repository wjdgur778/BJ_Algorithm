#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n;
int m;
vector<int>graph[32005];
int vec[32005] = { 0, };
priority_queue<int, vector<int>, greater<int>>p_q;

//��������

int main() {
	cin >> n >> m;
	//���� ���� �÷��ֱ�
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		vec[b] ++;
	}
	//���� ������ 0�� ģ���� ť�� �־� ����
	//���� ������ 0�� ģ������ ���� ���۵Ǿ�� ��
	for (int i = 1; i <= n; i++) {
		if (vec[i] == 0) p_q.push(i);
	}
	//���������� �ϵ�
	//�켱����ť�� �̿��Ͽ� ���� ���������� ���

	while (!p_q.empty()) {
		int cur = p_q.top();
		cout << cur<<" ";
		p_q.pop();
		for (int next : graph[cur]) {
			vec[next]--;
			if (!vec[next])p_q.push(next);
		}
	}

	return 0;
}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include<iostream>
//#include <queue>
//
//using namespace std;
//int in[32004], N, M, a, b;
//vector<int> adj[32004];
//priority_queue<int, vector<int>, greater<int>> q;
//int main() {
//    cin >> N>> M;
//    for (int i = 0; i < M; i++) {
//        int a, b;
//        cin >> a >> b;
//        adj[a].push_back(b);
//        in[b]++;
//    }
//    for (int i = 1; i <= N; i++)if (!in[i]) q.push(i);
//    while (q.size()) {
//        int here = q.top(); q.pop();
//        printf("%d ", here);
//        for (int there : adj[here]) {
//            in[there]--;
//            if (!in[there])q.push(there);
//        }
//    }
//    return 0;
//}