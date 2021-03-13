//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int INF = 987654321;
//
//vector<vector<int>>vec(21, vector<int>(21, 0));
//vector<vector<bool>>check(21, vector<bool>(21, false));
//int answer = 0;
//int N;
//int baby_shark = 2;
//int ate = 0;
//pair<int, int> baby_state;
//int x_way[4] = { 0,1,0,-1 };
//int y_way[4] = { 1,0,-1,0 };
//int special_x[4] = { 1,0,0,-1 };
//int special_y[4] = { 0,-1,1,0 };
//vector<vector<pair<int, int>>> fish(7);
////공간의 상태는 0,1,2,3,4,5,6,9 로 이루어 져있고,
////0: 빈 칸
////1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
////9 : 아기 상어의 위치
////아기 상어는 공간에 한 마리 있다.
////아기상어의 초기 크기는 2 이다.
////물고기와 크기가 같으면 이동이 가능하지만 먹을수 없다.
////아기상어보다 물고기가 더 크면  지나갈수 없다.
////아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.
//
////기본 bfs로 이동하되 
////아기상어의 크기를 동적으로 저장
////조건에 맞게 이동
////6개의 물고기 좌표를 알아놓으면 좋을까?
////
//int distance(pair<int, int> a) {
//	queue<pair<int, int>>q;
//	int level = 0;
//	q.push({ baby_state.first,baby_state.second });
//
//	while (!q.empty()) {
//		int size = q.size();
//		level++;
//
//		for (int i = 0; i < size; i++) {
//			int x = q.front().first;
//			int y = q.front().second;
//
//			for (int j = 0; j < 4; j++) {
//				int nx = x + x_way[j];
//				int ny = y + y_way[j];
//				if (nx == a.first && ny == a.second)return level;
//
//				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
//					if (vec[nx][ny] <= baby_shark) {
//						q.push({ nx,ny });
//					}
//
//				}
//			}
//			q.pop();
//		}
//	}
//
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> vec[i][j];
//			if (vec[i][j] == 9) {
//				baby_state = { i,j };
//				vec[i][j] = 0;
//			}
//		}
//	}
//	for (int i = N - 1; i >= 0; i--) {
//		for (int j = N - 1; j >= 0; j--) {
//
//			if (vec[i][j] != 0) {
//				fish[vec[i][j]].push_back({ i,j });
//			}
//		}
//	}
//
//	bool f = true;
//
//	/*
//	1.인접체크
//	2.이동
//	3. 1,2 반복
//	*/
//	bool move = true;
//
//	while (move) {
//		//인접체크
//		bool conti = false;
//		bool posi = true;
//		cout << baby_state.first << "," << baby_state.second << endl;
//		for (int i = 0; i < 4; i++) {
//			int x = baby_state.first + special_x[i];
//			int y = baby_state.second + special_y[i];
//			if (x >= 0 && x < N && y >= 0 && y < N && vec[x][y] != 0) {
//
//				if (vec[x][y] < baby_shark) {
//					//인접한 곳에 먹을 물고기가 있을 경우
//					posi = false;
//					vec[x][y] = 0;
//					baby_state = { x,y };
//					ate++;
//					answer++;
//
//					if (ate == baby_shark) {
//						baby_shark++;
//						ate = 0;
//					}
//					conti = true;
//					break;
//				}
//			}
//		}
//
//		//인접한 곳에 먹을 물고기가 없을 경우
//		if (posi) {
//			//먹을수 있는 친구부터
//			bool cant = true;
//			// i가 baby_shark-1부터 시작한다는 것은 이미 포문 안에서는 먹을수 있는 친구들만 보겠다는 것
//			int tmp_dist = 0;
//			int tmp_ans = 0;
//			pair<int, int> tmp_state = { 0,0 };
//			for (int i = baby_shark - 1; i >= 1; i--) {
//
//				if (fish[i].size() != 0) {
//					cant = false;
//					//우선순위대로 돌림
//					//거리가 가장 짧은 친구
//					//거리가 짧아질때만 갱신하고 아닐때는 그대로 가져온다.(포문 순서가 우선)
//				
//					for (int j = fish[i].size() - 1; j >= 0; j--)  {
//						if (vec[fish[i][j].first][fish[i][j].second] != 0) {
//							if (fish[i][j].first == baby_state.first && fish[i][j].second == baby_state.second)continue;
//							int d = distance(fish[i][j]);
//
//							if (tmp_dist == 0) {
//								tmp_ans = d;
//								tmp_dist = d;
//								tmp_state = fish[i][j];
//							}
//							else {
//								//돌아보고 짧았던 곳의 거리를 tmp_ans에 가져와 나중에 더해준다.
//								if (tmp_dist > d) {
//									tmp_ans = d;
//									tmp_state = fish[i][j];
//								}
//							}
//						}
//					}
//					ate++;
//					answer += tmp_ans;
//					vec[tmp_state.first][tmp_state.second] = 0;
//					baby_state = tmp_state;
//					if (ate == baby_shark) {
//						baby_shark++;
//						ate = 0;
//					}
//				}
//
//			}
//			if (cant)move = false;
//		}
//
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>>vec(21, vector<int>(21, 0));
int answer = 0;
int N;
int baby_shark = 2;
int ate = 0;
pair<int, int> baby_state;
int x_way[4] = { 0,1,0,-1 };
int y_way[4] = { 1,0,-1,0 };
int special_x[4] = { -1,0,0,1 };
int special_y[4] = { 0,-1,1,0 };
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vec[i][j] != 0 && vec[i][j] < baby_shark)return true;
		}
	}
	return false;
}
int distance() {
	queue<pair<int, int>>q;
	vector<vector<bool>>check_vec(21, vector<bool>(21, 0));
	vector < pair<int, int>>fish(0);
	int level = -1;
	bool f = true;

	q.push({ baby_state.first,baby_state.second });
	check_vec[baby_state.first][baby_state.second] = true;

	for (int j = 0; j < 4; j++) {
		int nx = q.front().first + special_x[j];
		int ny = q.front().second + special_y[j];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N && check_vec[nx][ny] == false) {
			//인접한 곳에 먹을수 있는 물고기가 있으면
			if (vec[nx][ny] != 0 && vec[nx][ny] < baby_shark && (nx != baby_state.first || ny != baby_state.second)) {
				baby_state.first = nx;
				baby_state.second = ny;
				vec[nx][ny] = 0;
				ate++;
				if (ate == baby_shark) {
					ate = 0;
					baby_shark++;
				}
				return 1;
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();

		if (fish.size() != 0)break;
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;

			if (vec[x][y] != 0 && vec[x][y] < baby_shark && (x != baby_state.first || y != baby_state.second)) {
				fish.push_back({ x,y });
			}

			for (int j = 0; j < 4; j++) {
				int nx = x + special_x[j];
				int ny = y + special_y[j];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N && check_vec[nx][ny] == false) {
					if (vec[nx][ny] <= baby_shark) {
						check_vec[nx][ny] = true;
						q.push({ nx,ny });
					}
					//인접한 곳에 먹을수 있는 물고기가 있으면

				}
			}
			q.pop();
		}
		level++;
	}
	if (fish.size() == 0) return 0;
	if (fish.size() == 1) {
		baby_state = fish[0];
		ate++;
		if (ate == baby_shark) {
			ate = 0;
			baby_shark++;
		}
		vec[fish[0].first][fish[0].second] = 0;
		return level;
	}
	pair<int, int>tmp;
	tmp = fish[0];

	//tmp에 고른 좌표가 나온다.
	for (int i = 1; i < fish.size(); i++) {
		if (tmp.first < fish[i].first)continue;

		else if (tmp.first == fish[i].first) {
			if (tmp.second > fish[i].second) {
				tmp = fish[i];
			}
		}
		else {
			tmp = fish[i];
		}
	}

	baby_state = tmp;
	ate++;
	if (ate == baby_shark) {
		ate = 0;
		baby_shark++;
	}
	vec[tmp.first][tmp.second] = 0;
	return level;

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> vec[i][j];
			if (vec[i][j] == 9) {
				baby_state = { i,j };
				vec[i][j] = 0;
			}
		}
	}
	int c = 0;
	while (true) {
		int w = distance();
		answer += w;
		c++;
		//cout << baby_state.first << "," << baby_state.second << " c : " << c << endl;
		//cout << w << endl;
		if (w == 0)break;
	}
	cout << answer;
	return 0;
}