#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*��ٸ��� ���μ��� �߰��ؼ�, ��ٸ� ������ ����� �����Ϸ��� �Ѵ�. �̶�, i�� ���μ��� ����� i���� ���;� �Ѵ�. �׷��� �ϱ� ���ؼ� �߰��ؾ� �ϴ� ���μ� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է����� �־����� ���μ��� ���� �����ϴ� ���� ����.

*/
// �� ���μ��� ���μ��� "¦��"�� �ְ� ������
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
//	//Ȧ���� Ȧ���� ������ ���� ����� ����.
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

//���°� �߰���.
//���°� �ٽ� ��������
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
//������ ���ؼ� ���μ��� �־�� ��Ÿ���� Ÿ����.
void choice(int idx,int cnt) {
	if (go()) {
		//cout << "asdf" << endl;
		answer = min(answer, cnt);
		return;
	}
	//3�� ������ ����.
	if (cnt == 3) {
	/*	for (int i = 0; i < 3; i++)cout <<a[i].first<<","<<a[i].second<<" ";
		cout << endl;*/
		return; 
	}
	//idx�� �Ѱ����� ������ �׻� ó������ ���� continue�� �����ϱ⶧���� ������ j�� �Ű������� �Ѱ��־� ����� ���μ��� ���� �ʰ��Ѵ�.(������ �Ǿ����)
	//���� idx�� �Ѱ��־� (����)�� ������ش�.
	//�ߺ��� continue�� ó���Ͽ���.
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
		//���μ��� ���۰� ���� �������� �Է�
		//go()�Լ����� ��ٸ��� Ÿ�� ������ �������´�.
		map[a][b] = 1;
		map[a][b+1] = 2;
	}
	choice(1,0);
	if (answer == 987654321)cout << -1;
	else cout << answer;
	return 0;
}