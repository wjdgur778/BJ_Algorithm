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

//격자판의 맨 왼쪽 위에서 시작해서 맨 오른쪽 아래까지 가야한다
//총 k 번만 체스의 나이트와 같이 움직일수 있다.
//인접한 네방향 혹은 나이트의 움직임으로 이동한다.
//나이트의 움직임으로 이동할때에는 장애물을 건너갈수 있다.
//최소한의 동작으로  departure to destination 
// '1'은 장애물

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
	//경로상에서 k를 보며 knight움직임을 얼마나 사용했는지 보아야한다.
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

			//horse 8방향
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

			//인접 4방향
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