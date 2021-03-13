#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 987654321;
int a[22][22]; //0���� �ʱ�ȭ �����ֱ� ���ؼ� ���������� ����
int N; // ������ ũ��
pair<int, int> Bsharkpos; // ������ ����
int vx[4] = { -1,0,0,1 }; //�Դ� �켱 ������ ���� ���¿��� ������ ����
int vy[4] = { 0,-1,1,0 };
int Bsharksize = 2; //�Ʊ����� ������(�ʱⰪ 2)
int cnt1 = 0; //���� ����� ������ ī��Ʈ �� ����(sizeŰ��µ� ���)
bool f = false;
/*ó���� ��Ž�ؼ� �Ʊ��� ��ġ�� �������� ��
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
/*ó������ dfs�� Ž���Ϸ� ������ FAIL �Ф�
void dfs(int n, int m) {
   int vx[4] = { -1,1,0,0 };
   int vy[4] = { 0,0,-1,1 };
   int size = 2; //�Ʊ����� ������(�ʱⰪ 2)
   int cnt1 = 0; //���� ����� ������ ī��Ʈ �� ����(sizeŰ��µ� ���)

   for (int i = 0; i < 4; i++) {
	  int px = n + vx[i];
	  int py = m + vy[i];

	  if (px<0 || px >N || py < 0 || py >N) //x��� y���� �ε��� ���� ������ ������ ������ �ٽ� for�� ó������
		 continue;

	  if (a[px][py] > size) //�Ʊ���� ũ�� ����
		 continue;
	  else if (a[px][py] == size) {// �Ʊ���� ũ�Ⱑ ������ �̵��� ��
		 c1[px][py] = true; // �湮ǥ��
		 dfs(px, py); // �̵�
	  }
	  else if (a[px][py] < size) { // �Ʊ���� ũ�Ⱑ ������ �����鼭(���� 0����) �̵�
		 a[px][py] = 0;
		 cnt1++;
		 c1[px][py] = true; //�湮ǥ��
		 if (size == cnt1) { // ���� ����� ������ �Ʊ��� ũ��� ������ size + 1
			size++; // ������ ��Ŵ
			cnt1 = 0; // ���� ����� ������ �ٽ� 0���� �ʱ�ȭ
		 }
		 dfs(px, py);
	  }
   }
}*/
int bfs() {
	queue<pair<int, int>> q;
	int c1[22][22]; //�湮ǥ��   
	int level = 0;
	q.push(Bsharkpos);
	c1[Bsharkpos.first][Bsharkpos.second] = true; // �湮üũ

	while (!q.empty()) {

		level++;
		int size = q.size(); // for���� ������ ť����� ������ �ʰ� �ϱ� ����
		vector<pair<int, int>> eat(0); //���� �� �ִ� ������� ��ġ�� �ε��� ���� �����ϴ� ����

		for (int s = 0; s < size; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int px = x + vx[i]; //���¿��ϸ� �����̱� ����
				int py = y + vy[i];

				if (px < 0 || px >= N || py < 0 || py >= N) //x��� y���� �ε��� ���� ������ ������ ������ �ٽ� for�� ó������ 
					continue;

				if (c1[px][py] == true) //�湮������ ���� ����
					continue;

				if (a[px][py] > Bsharksize) //�Ʊ���� ũ�Ⱑ ũ�� ����
					continue;


				q.push({ px,py });
				c1[px][py] = true; //�湮üũ

				if (a[px][py] < Bsharksize && a[px][py] != 0&&(Bsharkpos.first!=px|| Bsharkpos.second!=py)) //���� depth�� �ִ� �ֵ� �߿� size���� ���� �ֵ��� �ε��� ���� ���� ���Ϳ� ����
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
			if (a[i][j] == 9) { // �Ʊ��� ��ġ�� �޾ƿ�
				Bsharkpos = { i,j };
				a[i][j] = 0;
			}
		}
	}

	//Bsharkpos(N); // ó���� ��Ž �� ���ؼ� �Ʊ��� ��ġ�� ã��������
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

