#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
queue<pair<int, int>>q;
int n;
vector<vector<int>> vec(101, vector<int>(101, 0));

int x_way[4] = { 0,1,0,-1 };
int y_way[4] = { 1,0,-1,0 };
int main()
{
	int answer = 0;
	int M = 0;
	int m = 100;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (M < a)M = a;
			if (m > a)m = a;
			vec[i][j] = a;
		}
	}
	int cnt = 0;

	for (int i = m; i < M; i++) {
		vector<vector<bool>> check(100, vector<bool>(101, 0));
		cnt = 0;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {

				if (vec[j][k] > i&& check[j][k] == false) {
					cnt++;
					q.push({ j,k });
					check[j][k] = true;

					while (!q.empty()) {
						int size = q.size();
						for (int jj = 0; jj < size; jj++) {
							int x = q.front().first;
							int y = q.front().second;
							for (int ii = 0; ii < 4; ii++) {
								int nx = x + x_way[ii];
								int ny = y + y_way[ii];
								if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
									if (check[nx][ny] == false && vec[nx][ny] > i) {
										check[nx][ny] = true;
										q.push({ nx,ny });
									}
								}
							}
							q.pop();
						}

					}

				}
			}
		}
	

		answer = max(answer, cnt);
	}
	if (answer == 0)cout << 1;
	else cout << answer;
	return 0;
}