#include<iostream>
#include<vector>
using namespace std;
/*������ ���� ���� ���������� 6�������� ������ �� ������ ������ ���� �Ҽӵ� ������� �� ����, �� �������� �� 5���� ��⸦ ġ����. �������װ� ���� ��, ���ڰ� ������ �� ������ ��, ���º�, ���� ���� ������ ��������� �Ǻ��Ϸ��� �Ѵ�.*/
int answer[4] = { 0 };
int vec[6][3];
int result[6][3];

//��� ���帶�� ���� ������� �ܷ���� �����ϴ� �迭
int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

void dfs(int i, int r) {
	if (r == 15) {
		//�̹� �����̸� ����
		if (answer[i])return;

		//���� �𸣸� �� �ǽ�
		for (int ii = 0; ii < 6; ii++) {
			for (int jj = 0; jj < 3; jj++) {
				//�ϳ��� ���� ������ ����
				if (vec[ii][jj] != result[ii][jj])
					return;
			}
		}
		answer[i] = 1;
		return;
	}

	int t1 = team1[r];
	int t2= team2[r];
	// 0 ��, 1 ��, 2 ��
	result[t1][0]++; result[t2][2]++;
	dfs(i, r + 1);
	result[t1][0]--; result[t2][2]--;

	result[t1][1]++; result[t2][1]++;
	dfs(i, r + 1);
	result[t1][1]--; result[t2][1]--;

	result[t1][2]++; result[t2][0]++;
	dfs(i, r + 1);
	result[t1][2]--; result[t2][0]--;

}
int main() {
	//4���� ���̽�
	for (int i = 0; i < 4; i++) {
		//5����
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> vec[j][k];
			}
		}
		dfs(i, 0);
	}
	for (int i = 0; i < 4; i++)cout << answer[i] << endl;
	return 0;
}