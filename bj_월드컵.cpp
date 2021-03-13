#include<iostream>
#include<vector>
using namespace std;
/*월드컵 조별 최종 예선에서는 6개국으로 구성된 각 조별로 동일한 조에 소속된 국가들과 한 번씩, 각 국가별로 총 5번의 경기를 치른다. 조별리그가 끝난 후, 기자가 보내온 각 나라의 승, 무승부, 패의 수가 가능한 결과인지를 판별하려고 한다.*/
int answer[4] = { 0 };
int vec[6][3];
int result[6][3];

//경기 라운드마다 서로 어느팀이 겨루는지 저장하는 배열
int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

void dfs(int i, int r) {
	if (r == 15) {
		//이미 정답이면 리턴
		if (answer[i])return;

		//아직 모르면 평가 실시
		for (int ii = 0; ii < 6; ii++) {
			for (int jj = 0; jj < 3; jj++) {
				//하나라도 맞지 않으면 리턴
				if (vec[ii][jj] != result[ii][jj])
					return;
			}
		}
		answer[i] = 1;
		return;
	}

	int t1 = team1[r];
	int t2= team2[r];
	// 0 승, 1 무, 2 패
	result[t1][0]++; result[t2][2]++;
	dfs(i, r + 1);
	result[t1][0]--; result[t2][2]--;

	result[t1][1]++; result[t2][1]++;
	dfs(i, r + 1);
	result[t1][1]--; result[t2][1]--;

	result[t1][2]++; result[t2][0]++;
	dfs(i, r + 1);
	result[t1][2]--; result[t2][0]--;

}
int main() {
	//4개의 케이스
	for (int i = 0; i < 4; i++) {
		//5개국
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> vec[j][k];
			}
		}
		dfs(i, 0);
	}
	for (int i = 0; i < 4; i++)cout << answer[i] << endl;
	return 0;
}