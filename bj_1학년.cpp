#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int>vec;
long long dp[100][21];
/*상근이가 1학년 때, 덧셈, 뺄셈을 매우 좋아했다. 상근이는 숫자가 줄 지어있는 것을 보기만 하면, 마지막 두 숫자 사이에 '='을 넣고, 나머지 숫자 사이에는 '+' 또는 '-'를 넣어 등식을 만들며 놀고 있다. 예를 들어, "8 3 2 4 8 7 2 4 0 8 8"에서 등식 "8+3-2-4+8-7-2-4-0+8=8"을 만들 수 있다.

상근이는 올바른 등식을 만들려고 한다. 상근이는 아직 학교에서 음수를 배우지 않았고, 20을 넘는 수는 모른다. 따라서, 왼쪽부터 계산할 때, 중간에 나오는 수가 모두 0 이상 20 이하이어야 한다. 예를 들어, "8+3+2-4-8-7+2+4+0+8=8"은 올바른 등식이지만, 8+3+2-4-8-7이 음수이기 때문에, 상근이가 만들 수 없는 등식이다.

숫자가 주어졌을 때, 상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오.*/

//backtracking을 쓰는거같다.
//but dp

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][vec[0]] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]>0) {
				if (j - vec[i] >= 0) {
					dp[i][j - vec[i]] += dp[i-1][j];
				}
				if (j + vec[i] <= 20) {
					dp[i][j + vec[i]] += dp[i-1][j];
				}
			}
		}
	}
	cout << dp[N - 2][vec[N - 1]];

	return 0;
}