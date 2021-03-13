//#include<iostream>
//#include<vector>
//using namespace std;
//int N;
//int vec[17][17];
//int map[17][17];
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int a;
//			cin >> a;
//			if (a == 1)map[i][j] = 1;
//		}
//	}
//	if (map[N - 1][N - 1] == 1) {
//		cout << 0;
//		return 0;
//	}
//	for (int i = 2; i < N; i++)vec[1][i] = 1;
//
//	if (map[0][2] == 1 || map[1][1] == 1 || map[1][2] == 1) {
//		cout << 0;
//		return 0;
//	}
//	else {
//		cout << 1;
//		return 0;
//	}
//
//
//
//	for (int i = 1; i < N; i++) {
//		for (int j = 2; j < N; j++) {
//			if (i == 1) {
//				if (map[i - 1][j] != 1 && map[i][j - 1] != 1 && map[i][j] != 1)vec[i][j]
//			}
//			if (map[i - 1][j] != 1 && map[i][j - 1] != 1 && map[i][j] != 1)vec[i][j] += vec[i - 1][j - 1];
//			if (map[i][j] != 1)vec[i][j] += vec[i - 1][j];
//		}
//	}
//	cout << vec[N - 1][N - 1];
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
int N;
int vec[17][17];
pair<int, pair<int, int>> dp[17][17];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			vec[i][j] = a;
		}
	}
	if (vec[N - 1][N - 1] == 1) {
		cout << 0;
		return 0;
	}
	bool f = true;
	for (int i = 1; i < N; i++) {
		if (vec[0][i] == 1)f = false;
		if (f) {
			dp[0][i].first = 1;
		}
		else dp[0][i].first = 0;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (vec[i][j] == 0) {
				dp[i][j].first += dp[i][j - 1].second.first+dp[i][j-1].first;
				dp[i][j].second.second += dp[i - 1][j].second.first+ dp[i - 1][j].second.second;
			}
			if (vec[i][j] == 0 && vec[i][j-1] == 0 && vec[i-1][j] == 0){
				dp[i][j].second.first += dp[i - 1][j - 1].first + dp[i - 1][j - 1].second.first + dp[i - 1][j - 1].second.second;
			}
		}
	}
	cout << dp[N - 1][N - 1].first + dp[N - 1][N - 1].second.first + dp[N - 1][N - 1].second.second;
	return 0;
}