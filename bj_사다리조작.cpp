#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 이때, i번 세로선의 결과가 i번이 나와야 한다. 그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.

*/
// 두 세로선에 가로선이 "짝수"개 있게 만들자
//vector<int> ladder(11,1);
//int main() {
//	int n;
//	int m;
//	int h;
//	bool a = true;
//
//	int cnt = 0;
//	
//	cin >> n >> m >> h;
//	for (int i = 0; i < m; i++) {
//		int a;
//		int b;
//		cin >> a >> b;
//		ladder[b] *= -1;
//		ladder[b + 1] *= -1;
//	}
//	vector<int>calc;
//	for (int i = 1; i <= n; i++) {
//		if (ladder[i] == -1) {
//			cnt++;
//			calc.push_back(i);
//		}
//	}
//
//	//홀수가 홀수개 있으면 절대 만들수 없다.
//	if (cnt % 2 != 0)return -1;
//	int sum = 0;
//	for (int i = 0; i < calc.size(); i+=2) {
//		sum = calc[i + 1] - calc[i];
//		if (sum > 3)return -1;
//	}
//	cout << sum;
//	return 0;
//}
int map[50][50] = { 0 };
int check[50][50];
int n, m, h;
int answer = 987654321;

//고르는건 잘고른다.
//가는걸 다시 수정하자
bool go() {
	for (int i = 1; i <= n; i++) {
		int s = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][s] >= 1) {
				if (map[j][s] == 1) s += 1;
				else if (map[j][s] == 2) s -= 1;
			}
		}
		if (s != i)return false;
	}
	return true;
}
vector<pair<int,int>>a;
//조합을 통해서 가로선을 넣어보고 사타리를 타본다.
void choice(int idx,int cnt) {
	if (go()) {
		//cout << "asdf" << endl;
		answer = min(answer, cnt);
		return;
	}
	//3개 까지만 본다.
	if (cnt == 3) {
	/*	for (int i = 0; i < 3; i++)cout <<a[i].first<<","<<a[i].second<<" ";
		cout << endl;*/
		return; 
	}
	//idx를 넘겨주지 않으면 항상 처음부터 보고 continue를 진행하기때문에 이전의 j를 매개변수로 넘겨주어 골랐던 가로선은 고르지 않게한다.(순열이 되어버림)
	//따라서 idx를 넘겨주어 (조합)을 만들어준다.
	//중복은 continue로 처리하였다.
	for (int i = 1; i <= n; i++) {
		for (int j = idx; j <= h; j++) {
			if (map[j][i] >= 1 || map[j][i+1]>=1)continue;
			map[j][i] = 1;
			map[j][i + 1] = 2;
			a.push_back({j,i});
 			choice(j, cnt + 1);
			a.pop_back();
			map[j][i] = 0;
			map[j][i + 1] = 0;
		}
	}
}

int main() {

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b;
		//가로선의 시작과 끝을 구분지어 입력
		//go()함수에서 사다리를 타는 방향을 결정짓는다.
		map[a][b] = 1;
		map[a][b+1] = 2;
	}
	choice(1,0);
	if (answer == 987654321)cout << -1;
	else cout << answer;
	return 0;
}