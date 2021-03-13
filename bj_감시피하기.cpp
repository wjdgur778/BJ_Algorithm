//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//
//vector<vector<char>>map(7, vector<char>(7, 'X'));
//vector<pair<int, int >>T;
//vector<pair<int, int >>X;
//vector<bool>check(25, false);
//int n;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//bool f = false;
//bool bfs(int i) {
//	vector<vector<bool>>ck(7, vector<bool>(7, false));
//	queue<pair<int, int>>q;
//	q.push(T[i]);
//	//피할수 없으면 그냥 break;
//	while (!q.empty()) {
//		int size = q.size();
//		for (int j = 0; j < size; j++) {
//			int x = q.front().first;
//			int y = q.front().second;
//			for (int jj = 0; jj < 4; jj++) {
//				int nx = x + dx[jj];
//				int ny = y + dy[jj];
//				if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1||ck[nx][ny]==true)continue;
//				if (map[nx][ny] == 'T'|| map[nx][ny] == 'O')continue;
//				if (map[nx][ny] == 'S') {
//					return true;
//				}
//				ck[nx][ny] = true;
//				q.push({nx,ny});
//			}
//			q.pop();
//		}
//	}
//	return false;
//}
//
//void dfs(int idx, int cnt) {
//	if (f)return;
//
//
//	if (cnt == 3) {
//		int c = 0;
//		int ans = 0;
//		while (c < T.size()) {
//			//학생들이 잡히면 그냥 바로 다음 obstract를 뽑아야함
//			if (bfs(c)) {
//				return;
//			}
//			else {
//				c++;
//				ans++;
//			}
//		}
//		//학생들이 모두 잡히지 않으면 답을 내자
//		if (ans == T.size()) {
//			f = true;
//		}
//	}
//	for (int i = idx; i < X.size(); i++) {
//		if (check[i] == true)continue;
//		check[i] = true;
//		map[X[i].first][X[i].second] = 'O';
//		dfs(i, cnt + 1);
//		map[X[i].first][X[i].second] = 'X';
//		check[i] = false;
//	}
//}
//
//
//int main() {
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 'T')T.push_back({ i,j });
//			if (map[i][j] == 'X')X.push_back({ i,j });
//		}
//	}
//	dfs(0, 0);
//	if (f)cout << "YES";
//	else cout << "NO";
//
//	return 0;
//}

/*
처음에는 선생님이 움직이면서 감시하는 것인줄 알았다만 ,,
선생님은 그자리에 서서 감시하는것이었다....
*/
#include<iostream>
#include<vector>
using namespace std;


vector<vector<char>>map(7, vector<char>(7, 'X'));
vector<pair<int, int >>T;
vector<pair<int, int >>X;
vector<bool>check(25, false);
int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool f = false;
bool find_student() {
	for (int i = 0; i < T.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int nx = T[i].first + dx[j];
			int ny = T[i].second + dy[j];
			while (true) {
				if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1 || map[nx][ny] == 'O')break;
				if (map[nx][ny] == 'S') {
					//학생을 잡은경우
					return true;
				}
				nx += dx[j];
				ny += dy[j];
			}
		}
	}
	//선생님이 아무도 학생을 발견하지 못한 경우
	return false;
}

void dfs(int idx, int cnt) {
	if (f)return;
	if (cnt == 3) {
		if (find_student()) {
			return;
		}
		else {
			f = true;
			return;
		}
	}
	for (int i = idx; i < X.size(); i++) {
		if (check[i] == true)continue;
		check[i] = true;
		map[X[i].first][X[i].second] = 'O';
		dfs(i, cnt + 1);
		map[X[i].first][X[i].second] = 'X';
		check[i] = false;
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')T.push_back({ i,j });
			if (map[i][j] == 'X')X.push_back({ i,j });
		}
	}
	dfs(0, 0);
	if (f)cout << "YES";
	else cout << "NO";
	return 0;
}