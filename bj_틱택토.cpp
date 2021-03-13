//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
///*틱택토 게임은 두 명의 사람이 번갈아가며 말을 놓는 게임이다. 게임판은 3×3 격자판이며, 처음에는 비어 있다. 두 사람은 각각 X 또는 O 말을 번갈아가며 놓는데, 반드시 첫 번째 사람이 X를 놓고 두 번째 사람이 O를 놓는다. 어느 때든지 한 사람의 말이 가로, 세로, 대각선 방향으로 3칸을 잇는 데 성공하면 게임은 즉시 끝난다. 게임판이 가득 차도 게임은 끝난다.
//
//게임판의 상태가 주어지면, 그 상태가 틱택토 게임에서 발생할 수 있는 최종 상태인지를 판별하시오.
//*/
//string tic;
//vector<string>answer;
//vector<vector<bool>>x_check;
//bool f = false;
//bool check(char map[3][3], char a) {
//
//	for (int i = 0; i < 3; i++) {
//		int cnt = 0;
//		for (int j = 0; j < 3; j++) {
//			if (map[i][j] == a)cnt++;
//		}
//		if (cnt == 3) {
//			return true;
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		int cnt = 0;
//		for (int j = 0; j < 3; j++) {
//			if (map[j][i] == a)cnt++;
//		}
//		if (cnt == 3) {
//			return true;
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i < 3; i++) {
//		if (map[i][i] == a)cnt++;
//	}
//	if (cnt == 3) {
//		return true;
//	}
//
//	cnt = 0;
//	for (int i = 0; i < 3; i++) {
//		if (map[0 + i][2 - i] == a)cnt++;
//	}
//	if (cnt == 3) {
//		return true;
//	}
//	return false;
//}
//
//void dfs(char tmp[3][3], vector<pair<int, int>>x_vec, int x, int y, int cnt) {
//	//cout << "x  : " << x << " y :  " << y << endl;
//	if (f)return;
//	if (cnt == 3) {
//		if (check(tmp, 'X')) {
//			return;
//		}
//		else {
//			f = true;
//			return;
//		}
//	}
//	for (int i = 0; i < x_vec.size(); i++) {
//		int nx = x_vec[i].first;
//		int ny = x_vec[i].second;
//		if (x_check[nx][ny] == true)continue;
//		x_check[nx][ny] = true;
//		tmp[nx][ny] = 'X';
//		dfs(tmp, x_vec, nx, ny, cnt + 1);
//		tmp[nx][ny] = ' ';
//		x_check[nx][ny] = false;
//	}
//}
//
//int main() {
//
//	while (1) {
//		cin >> tic;
//		int empty = 0;
//		int o = 0;
//		int x = 0;
//		char map[3][3];
//		char t[3][3];
//		vector<pair<int, int>>x_vec;
//		vector<vector<bool>>c(3, vector<bool>(3, false));
//		x_check = c;
//
//		if (tic == "end") break;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				map[i][j] = tic[3 * i + j];
//				if (map[i][j] == 'O')o += 1;
//				else if (map[i][j] == 'X') {
//					x += 1;
//					x_vec.push_back({ i,j });
//				}
//				else empty += 1;
//			}
//		}
//		if (empty > 0) {
//			if (o > x)answer.push_back("invalid");
//			else if (o == x) {
//				//o가 빙고인지 확인
//				if (check(map, 'O'))answer.push_back("valid");
//				else answer.push_back("invalid");
//			}
//			else if (o + 1 == x) {
//				//x가 빙고인지 확인
//				if (check(map, 'X'))answer.push_back("valid");
//				else if (check(map, 'O')) {
//					answer.push_back("invalid");
//				}
//				else answer.push_back("invalid");
//
//			}
//			else answer.push_back("invalid");
//		}
//		//빈칸이 없을때
//		//O로 빙고가 있으면 탈락
//		else {
//			if (o > x) {
//				answer.push_back("invalid");
//				continue;
//			}
//			if (check(map, 'O')) {
//				answer.push_back("invalid");
//			}
//			//X로 빙고가 있을때는 순서를 조합해보아야 한다.
//			else {
//				char tmp[3][3];
//				for (int i = 0; i < 9; i++) {
//					tmp[i / 3][i % 3] = 'O';
//				}
//				x_check[x_vec[0].first][x_vec[0].second] = true;
//				f = false;
//				dfs(tmp, x_vec, x_vec[0].first, x_vec[0].second, 0);
//				if (f) answer.push_back("valid");
//				else answer.push_back("invalid");
//			}
//		}
//	}
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer[i] << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//경우의수 따지기
int main() {
	string a;
	while (1) {
		cin >> a;
		if (a == "end")break;
		vector<vector<char>>game(3, vector<char>(3, ' '));
		for (int i = 0; i < 9; i++) {
			game[i / 3][i % 3] = a[i];
		}


	}
	return 0;
}