#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	int answer = 1;
	vector<int>A(1001);
	vector<int>dp(1001,1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; 
		cin >> a;
		A[i] = a;
	}
	for (int i = 1; i < N; i++) {
		int m=0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				m = max(dp[j], m);
			}
		}
		dp[i] = m+1;
	}
	for (int i = 0; i < dp.size(); i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;
	return 0;
}