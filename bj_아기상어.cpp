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
////������ ���´� 0,1,2,3,4,5,6,9 �� �̷�� ���ְ�,
////0: �� ĭ
////1, 2, 3, 4, 5, 6: ĭ�� �ִ� ������� ũ��
////9 : �Ʊ� ����� ��ġ
////�Ʊ� ���� ������ �� ���� �ִ�.
////�Ʊ����� �ʱ� ũ��� 2 �̴�.
////������ ũ�Ⱑ ������ �̵��� ���������� ������ ����.
////�Ʊ���� ����Ⱑ �� ũ��  �������� ����.
////�Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 �����Ѵ�. ���� ���, ũ�Ⱑ 2�� �Ʊ� ���� ����⸦ 2���� ������ ũ�Ⱑ 3�� �ȴ�.
//
////�⺻ bfs�� �̵��ϵ� 
////�Ʊ����� ũ�⸦ �������� ����
////���ǿ� �°� �̵�
////6���� ����� ��ǥ�� �˾Ƴ����� ������?
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
//	1.����üũ
//	2.�̵�
//	3. 1,2 �ݺ�
//	*/
//	bool move = true;
//
//	while (move) {
//		//����üũ
//		bool conti = false;
//		bool posi = true;
//		cout << baby_state.first << "," << baby_state.second << endl;
//		for (int i = 0; i < 4; i++) {
//			int x = baby_state.first + special_x[i];
//			int y = baby_state.second + special_y[i];
//			if (x >= 0 && x < N && y >= 0 && y < N && vec[x][y] != 0) {
//
//				if (vec[x][y] < baby_shark) {
//					//������ ���� ���� ����Ⱑ ���� ���
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
//		//������ ���� ���� ����Ⱑ ���� ���
//		if (posi) {
//			//������ �ִ� ģ������
//			bool cant = true;
//			// i�� baby_shark-1���� �����Ѵٴ� ���� �̹� ���� �ȿ����� ������ �ִ� ģ���鸸 ���ڴٴ� ��
//			int tmp_dist = 0;
//			int tmp_ans = 0;
//			pair<int, int> tmp_state = { 0,0 };
//			for (int i = baby_shark - 1; i >= 1; i--) {
//
//				if (fish[i].size() != 0) {
//					cant = false;
//					//�켱������� ����
//					//�Ÿ��� ���� ª�� ģ��
//					//�Ÿ��� ª�������� �����ϰ� �ƴҶ��� �״�� �����´�.(���� ������ �켱)
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
//								//���ƺ��� ª�Ҵ� ���� �Ÿ��� tmp_ans�� ������ ���߿� �����ش�.
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
			//������ ���� ������ �ִ� ����Ⱑ ������
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
					//������ ���� ������ �ִ� ����Ⱑ ������

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

	//tmp�� �� ��ǥ�� ���´�.
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