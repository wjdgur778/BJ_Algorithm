#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> vec(15,vector<int>(15,1));
int main() {
	int n, m, k;
	int answer = 0;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 || j == 0)continue;
				vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
			}
		}
		cout<< vec[n - 1][m - 1];
		return 0;
	}
	else {
		int c_n = 0;
		int c_m = 0;
		if (k % m == 0) {
			c_n = (k / m) ;
			c_m = m;
		}
		else {
			c_n = (k / m) +1;
			c_m = ( k % m)  ;
		}

		for (int i = 0; i < c_n; i++) {
			for (int j = 0; j < c_m; j++) {
				if (i == 0 || j == 0)continue;
				vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
			}
		}
		answer += vec[c_n - 1][c_m - 1];
		vector<vector<int>> tvec(15, vector<int>(15, 1));

		for (int i = 0; i < n-c_n+1; i++) {
			for (int j = 0; j < m-c_m+1; j++) {
				if (i == 0 || j == 0)continue;
				tvec[i][j] = tvec[i - 1][j] + tvec[i][j - 1];
			}
		}
		answer *= tvec[n - c_n][m - c_m];
	}
	cout << answer;
	return 0;
}