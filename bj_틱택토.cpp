//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
///*ƽ���� ������ �� ���� ����� �����ư��� ���� ���� �����̴�. �������� 3��3 �������̸�, ó������ ��� �ִ�. �� ����� ���� X �Ǵ� O ���� �����ư��� ���µ�, �ݵ�� ù ��° ����� X�� ���� �� ��° ����� O�� ���´�. ��� ������ �� ����� ���� ����, ����, �밢�� �������� 3ĭ�� �մ� �� �����ϸ� ������ ��� ������. �������� ���� ���� ������ ������.
//
//�������� ���°� �־�����, �� ���°� ƽ���� ���ӿ��� �߻��� �� �ִ� ���� ���������� �Ǻ��Ͻÿ�.
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
//				//o�� �������� Ȯ��
//				if (check(map, 'O'))answer.push_back("valid");
//				else answer.push_back("invalid");
//			}
//			else if (o + 1 == x) {
//				//x�� �������� Ȯ��
//				if (check(map, 'X'))answer.push_back("valid");
//				else if (check(map, 'O')) {
//					answer.push_back("invalid");
//				}
//				else answer.push_back("invalid");
//
//			}
//			else answer.push_back("invalid");
//		}
//		//��ĭ�� ������
//		//O�� ���� ������ Ż��
//		else {
//			if (o > x) {
//				answer.push_back("invalid");
//				continue;
//			}
//			if (check(map, 'O')) {
//				answer.push_back("invalid");
//			}
//			//X�� ���� �������� ������ �����غ��ƾ� �Ѵ�.
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

//����Ǽ� ������
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