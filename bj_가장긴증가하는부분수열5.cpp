#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
20
2 54 77 21 14 32 68 47 22 10 6 85 77 85 111 140 25 43 31 11
*/
int N;
int answer = 0;
vector<long long>A; 
vector<long long>ans;
vector<int>dp(1000001,1);
vector<int>index;
/*
LIS의 최대 길이를 구하면 정확한 정답 배열을 알수 없다.
lower_bound()함수를 통해(이분탐색기반) 배열을 재배치 시키면서 
배치되었던 자리를 기억해간다.
기억한 자리를 역순으로 찾아가 정답을 찾는다.
많은 반례들과 예제들을 통해 "역순"의 해답을 찾았다.
lower_bound() 또한 이분탐색알고리즘 분류를 통해 알았다.
이분탐색으로도 구현 가능하다.
*/
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0; 
		cin >> a;
		A.push_back(a);
	}
	ans.push_back(A[0]);
	index.push_back(0);
	for (int i = 1; i < N; i++) {
		if (ans[ans.size() - 1] < A[i]) {
			ans.push_back(A[i]);
			dp[i] = ans.size();
			index.push_back(ans.size()-1);
		}
		else { 
			int idx = 0;
			idx = lower_bound(ans.begin(), ans.end(), A[i]) - ans.begin();
			ans[idx] = A[i];
			index.push_back(idx);
		}
	}

	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;

	vector<long long>tmp;
	for (int i = N - 1; i >= 0; i--) {
		if (index[i] == answer - 1) {
			tmp.push_back(A[i]);
			answer--;
		}
	}
	for (int i = 0; i < index.size(); i++) {
		cout << index[i] << " ";
	}
	cout << endl;
	for (int i = tmp.size() - 1; i >= 0; i--) cout << tmp[i] << " ";
		return 0;
}