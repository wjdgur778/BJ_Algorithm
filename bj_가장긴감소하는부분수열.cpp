#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*20
2 54 77 21 14 32 68 47 22 10 6 85 77 85 111 140 25 43 31 11*/
// 5 4 3 2 1
int N;
vector<int>A;
vector<int>lds;
int answer=1;
int main() {
	int a;
	cin >> N;
	cin >> a;
	lds.push_back(a);
	for (int i = 1; i < N; i++) {
		cin >> a;
		if (lds[lds.size() - 1] > a) {
			lds.push_back(a);
		}
		else {
			int s = 0;
			int e = lds.size() - 1;
			int target_idx = 0;
			while (s <= e) {
				int mid = (s + e) / 2;

				if (lds[mid] > a) {
					s = mid + 1;
				}
				else {
					e = mid - 1;
					target_idx = mid;
				}
			}
			lds[target_idx] = a;
		
		}
		for (int i = 0; i < lds.size(); i++)cout << lds[i] << " ";
		cout << endl;
		answer = max(answer,int(lds.size()));
	}
	cout << answer;
	return 0;
}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int N;
//	int answer = 1;
//	vector<int>A(1001);
//	vector<int>dp(1001, 1);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int a;
//		cin >> a;
//		A[i] = a;
//	}
//	for (int i = 1; i < N; i++) {
//		int m = 0;
//		for (int j = 0; j < i; j++) {
//			if (A[i] < A[j]) {
//				m = max(dp[j], m);
//			}
//		}
//		dp[i] = m + 1;
//	}
//	for (int i = 0; i < dp.size(); i++) {
//		answer = max(answer, dp[i]);
//	}
//	cout << answer;
//	return 0;
//}