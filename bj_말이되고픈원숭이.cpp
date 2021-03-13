#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int k;
int w;
int h;
vector<vector<int>> vec(200, vector<int>(200, 0));
bool check[201][201][32];
int x_way[4] = { 0,1,0,-1 };
int y_way[4] = { 1,0,-1,0 };

int hx_way[8] = { -1,-2,-2,-1,1,2 ,2,1 };
int hy_way[8] = { 2,1,-1,-2,-2,-1,1,2 };
queue <pair<pair<int, int>,int>> m_q;

//�������� �� ���� ������ �����ؼ� �� ������ �Ʒ����� �����Ѵ�
//�� k ���� ü���� ����Ʈ�� ���� �����ϼ� �ִ�.
//������ �׹��� Ȥ�� ����Ʈ�� ���������� �̵��Ѵ�.
//����Ʈ�� ���������� �̵��Ҷ����� ��ֹ��� �ǳʰ��� �ִ�.
//�ּ����� ��������  departure to destination 
// '1'�� ��ֹ�

int main() {
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			vec[i][j] = a;
		}
	}
	check[0][0][0] = true;
	m_q.push({ {0,0 },0 });

	int level = 0;
	int f = false;
	int cnt;
	//��λ󿡼� k�� ���� knight�������� �󸶳� ����ߴ��� ���ƾ��Ѵ�.
	while (!m_q.empty()) {
		int size = m_q.size();

		for (int i = 0; i < size; i++) {
			int x = m_q.front().first.first;
			int y = m_q.front().first.second;
			int horse = m_q.front().second;

			//cout <<"("<< x << "," << y <<") h : "<<horse<< endl;

			if (x == h - 1 && y == w - 1) {
				f = true;
				if (horse <= k) {
					cout << level;
					return 0;
				}
			}

			//horse 8����
			if (horse < k) {
				for (int j = 0; j < 8; j++) {
					int n_x = x + hx_way[j];
					int n_y = y + hy_way[j];

					if (n_x >= 0 && n_x < h && n_y >= 0 && n_y < w) {
						if (check[n_x][n_y][horse+1] == false && vec[n_x][n_y] != 1) {
							check[n_x][n_y][horse+1] = true;

							m_q.push({ {n_x,n_y },horse + 1 });
						}

					}

				}
			}

			//���� 4����
			for (int j = 0; j < 4; j++) {
				int n_x = x + x_way[j];
				int n_y = y + y_way[j];

				if (n_x >= 0 && n_x < h && n_y >= 0 && n_y < w) {
					if (check[n_x][n_y][horse]== false && vec[n_x][n_y] != 1) {
						check[n_x][n_y][horse] = true;
						m_q.push({ { n_x,n_y},horse });
					}

				}

			}
		
			m_q.pop();
		}
		level++;
	}
	if (f == false) {
		cout << -1;
	}

	return 0;
}