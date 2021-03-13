#include<vector>
#include<iostream>
#include<queue>
using namespace std;

queue<int>q;
int n, m;
vector<int>map[20001];
vector<bool> check(20001,false);
int main()
{
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	q.push(1);
	check[1] = true;

	int size = 0;
	int num = 0;
	while (!q.empty()) {
		cnt++;
		size = q.size();
		num = n;

		for (int i = 0; i < size; i++) {
			int next = q.front();
			cout << size << " ";
			if (num >=next) {
				num = next;
			}
			for (int j = 0; j < map[next].size(); j++) {
				if (check[map[next][j]] == false) {
					check[map[next][j]] = true;
					q.push(map[next][j]);
				}
			}
			q.pop();
		}
		cout << endl;
	}
	cout << num << " "<< cnt-1<<" " << size;
	return 0;
}