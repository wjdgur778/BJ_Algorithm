#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 987654321;
int a[22][22]; //0으로 초기화 시켜주기 위해서 전역변수로 선언
int N; // 공간의 크기
pair<int, int> Bsharkpos; // 순서쌍 생성
int vx[4] = { -1,0,0,1 }; //먹는 우선 순위에 따라서 상좌우하 순서로 넣음
int vy[4] = { 0,-1,1,0 };
int Bsharksize = 2; //아기상어의 사이즈(초기값 2)
int cnt1 = 0; //먹은 물고기 개수를 카운트 할 변수(size키우는데 사용)
bool f = false;
/*처음에 완탐해서 아기상어 위치를 받으려고 함
void Bshark	pos(int num) {
   for (int i = 0; i < num; i++) {
	  for (int j = 0; j < num; j++) {
		 if (a[i][j] == 9) {
			x = i;
			y = j;
		 }
	  }
   }
}*/
/*처음에는 dfs로 탐색하려 했지만 FAIL ㅠㅠ
void dfs(int n, int m) {
   int vx[4] = { -1,1,0,0 };
   int vy[4] = { 0,0,-1,1 };
   int size = 2; //아기상어의 사이즈(초기값 2)
   int cnt1 = 0; //먹은 물고기 개수를 카운트 할 변수(size키우는데 사용)

   for (int i = 0; i < 4; i++) {
	  int px = n + vx[i];
	  int py = m + vy[i];

	  if (px<0 || px >N || py < 0 || py >N) //x축과 y축의 인덱스 값이 정해진 범위를 넘으면 다시 for문 처음으로
		 continue;

	  if (a[px][py] > size) //아기상어보다 크면 못감
		 continue;
	  else if (a[px][py] == size) {// 아기상어랑 크기가 같으면 이동만 함
		 c1[px][py] = true; // 방문표시
		 dfs(px, py); // 이동
	  }
	  else if (a[px][py] < size) { // 아기상어보다 크기가 작으면 먹으면서(값을 0으로) 이동
		 a[px][py] = 0;
		 cnt1++;
		 c1[px][py] = true; //방문표시
		 if (size == cnt1) { // 먹은 물고기 개수가 아기상어 크기랑 같으면 size + 1
			size++; // 레벨업 시킴
			cnt1 = 0; // 먹은 물고기 개수는 다시 0으로 초기화
		 }
		 dfs(px, py);
	  }
   }
}*/
int bfs() {
	queue<pair<int, int>> q;
	int c1[22][22]; //방문표시   
	int level = 0;
	q.push(Bsharkpos);
	c1[Bsharkpos.first][Bsharkpos.second] = true; // 방문체크

	while (!q.empty()) {

		level++;
		int size = q.size(); // for문을 돌때에 큐사이즈가 변하지 않게 하기 위함
		vector<pair<int, int>> eat(0); //먹을 수 있는 물고기의 위치의 인덱스 쌍을 저장하는 벡터

		for (int s = 0; s < size; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int px = x + vx[i]; //상좌우하를 움직이기 위함
				int py = y + vy[i];

				if (px < 0 || px >= N || py < 0 || py >= N) //x축과 y축의 인덱스 값이 정해진 범위를 넘으면 다시 for문 처음으로 
					continue;

				if (c1[px][py] == true) //방문했으면 가지 않음
					continue;

				if (a[px][py] > Bsharksize) //아기상어보다 크기가 크면 못감
					continue;


				q.push({ px,py });
				c1[px][py] = true; //방문체크

				if (a[px][py] < Bsharksize && a[px][py] != 0&&(Bsharkpos.first!=px|| Bsharkpos.second!=py)) //같은 depth에 있는 애들 중에 size보다 작은 애들의 인덱스 순서 쌍을 벡터에 넣음
					eat.push_back({ px,py });
			}
		}

		if (!eat.empty()) {
			f = true;
			if (eat.size() == 1) {
				Bsharkpos = eat[0];
				cnt1++;
				a[Bsharkpos.first][Bsharkpos.second] = 0;
				if (Bsharksize == cnt1) {
					Bsharksize++;
					cnt1 = 0;
				}
				return level;
			}

			else {
				pair<int, int>tmp;
				tmp = eat[0];
				for (int j = 1; j < eat.size(); j++) {
					if (tmp.first > eat[j].first) {
						tmp = eat[j];
					}
					else if (tmp.first == eat[j].first) {
						if (tmp.second > eat[j].second) {
							tmp = eat[j];
						}
					}
				}

				Bsharkpos = tmp;
				cnt1++;
				a[Bsharkpos.first][Bsharkpos.second] = 0;
				if (Bsharksize == cnt1) {
					Bsharksize++;
					cnt1 = 0;
				}
				return level;
			}
		}

	}

	return 0;
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) { // 아기상어 위치를 받아옴
				Bsharkpos = { i,j };
				a[i][j] = 0;
			}
		}
	}

	//Bsharkpos(N); // 처음에 완탐 한 번해서 아기상어 위치를 찾으려고함
	//dfs(x, y);


	int answer = 0;
	while (1) {
		cout << Bsharkpos.first << "," << Bsharkpos.second << endl;
		int ans = bfs();
		answer += ans;
		if (ans == 0) {
			cout << answer ;
			return 0;
		}
	}
	return 0;
}

