#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int>A;
vector<int>dp_1(1001,1);
vector<int>dp_2(1001,1);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 1; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j <= i; j++) {
			if (A[i] > A[j]) {
				tmp = max(tmp, dp_1[j]);
			}
		}
		dp_1[i] = tmp + 1;
	}
	for (int i = N-2; i >=0; i--) {
		int tmp1 = 0;
		for (int j = N - 1; j >= i; j--) {
			if (A[i] > A[j]) {
				tmp1 = max(tmp1, dp_2[j]);
			}
		}
		dp_2[i] = tmp1 + 1;
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, (dp_1[i] + dp_2[i]));
	}
	cout << answer-1;

	return 0;
}