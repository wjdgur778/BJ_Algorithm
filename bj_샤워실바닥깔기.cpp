#include<iostream>
#include<vector>
using namespace std;
int k;
pair <int, int> t;
int n=1;
int vec[4][4];
int lx, ly;

/*
������ �α԰� �Ʒüҿ� �Լ��ϴ� ���̴�. ��� ��縦 ��ġ�� ��Ȱ������ ���ƿͼ� �����µ� ���ڱ� ������ �������� �α��� �̸��� �θ��� ���� �ƴѰ�. ��Ȳ�� ä�� ���󰬴��� �̹��� ���ؼ��� �ƴ��İ� ����Ҵ�. �� �༮�� ������ �ٴ��� ��Ҵµ�, ����� ��ġ���� ���ƹ��ȴٸ鼭 ���� �б� ����� �α԰� �ٽ� ���� ���̾���.

��� Ÿ���� ���� ����ϴ� �αԴ� �������� ������ ���簢���̸鼭 �� ���� ���̰� 2�� ��������� ����� �˾Ƴ´�. �ؼ��� ��������� ����ؼ� 2x2 ũ���� Ÿ�Ϸ� �ٴ��� ���� ä�� �� ������, ������ �̷��� �ϸ� ������� �־�� �� ��ġ�� ��� ���� ���ٴ� ���̴�. �̷����� ����� �����ϴٰ� 4ĭ�� �����ϴ� ���簢�� Ÿ�� ��� 3ĭ�� �����ϴ� ���� ����� Ÿ���� ����ϸ� �� �� ���ٴ� ������ �޾Ҵ�.

�׷��� ���� Ÿ���� ��� ä���� �ұ�? �����ϴ� ��ģ �αԴ� �����п��� �� ����� ã�ƴ޶�� ��Ź�ߴ�. ù������ ��Ȱ������ ���� ����� ���� ������ �������� ��������.
*/

//Divide & Conquer
//�ٵ� �̰� �� ���������ϱ�?
//�ǳ��ϰ�ʹ�.

bool check(int x, int y) {
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			if (i == 2 * k - t.second && j == t.first - 1) {
				lx = x;
				ly = y;
				return false;
			}
		}
	}
	return true;
}
void attach(int x,int y) {
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			vec[i][j] = n;
		}
	}
	n++;
	return;
}
int main() {
	cin >> k;
	cin >> t.first >> t.second;
	if (k == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == 2 * k - t.second && j == t.first - 1) {
					cout << -1 << " ";
				}
				else cout << 1 << " ";
			}
			if(i!=1) cout << endl;
		}
	}
	else {
		for (int i = 0; i < 4; i += 2) {
			for (int j = 0; j < 4; j += 2) {
				if (check(i, j)) {
					attach(i, j);
				}
			}
		}
		attach(1, 1);
		attach(lx, ly);
		vec[2 * k - t.second][t.first - 1]=-1;
		for (int i = 0; i < 2 * k; i++) {
			for (int j = 0; j < 2 * k; j++) {
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}