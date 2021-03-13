#include<iostream>
#include<vector>
using namespace std;
/*상근이가 살고있는 동네에는 빌딩 N개가 한 줄로 세워져 있다. 모든 빌딩의 높이는 1보다 크거나 같고, N보다 작거나 같으며, 같은 높이를 가지는 빌딩은 없다. 상근이는 학교 가는 길에 가장 왼쪽에 서서 빌딩을 몇 개 볼 수 있는지 보았고, 집에 돌아오는 길에는 가장 오른쪽에 서서 빌딩을 몇 개 볼 수 있는지 보았다.

상근이는 가장 왼쪽과 오른쪽에서만 빌딩을 봤기 때문에, 빌딩이 어떤 순서로 위치해있는지는 알 수가 없다.

빌딩의 개수 N과 가장 왼쪽에서 봤을 때 보이는 빌딩의 수 L, 가장 오른쪽에서 봤을 때 보이는 빌딩의 수 R이 주어졌을 때, 가능한 빌딩 순서의 경우의 수를 구하는 프로그램을 작성하시오.

예를 들어, N = 5, L = 3, R = 2인 경우에 가능한 빌딩의 배치 중 하나는 1 3 5 2 4이다.*/


int N;
int L;
int R;
int M = 1000000007;
//1000000007
//N개 빌딩
long long building[101][101][101] = { 0, };

void solution() {
	building[1][1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= i; k++) {
				if (j == 1 && k == 1)building[i][j][k] = 0;
				building[i][j][k] = ( building[i - 1][j - 1][k] + building[i - 1][j][k - 1] + building[i - 1][j][k] * (i - 2) ) % M;
			}
		}
	}
	return;
}




	int main() {
		cin >> N >> L >> R;
		solution();
		cout << building[N][L][R];
		return 0;
	}