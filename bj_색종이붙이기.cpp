#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// https://www.acmicpc.net/problem/17136

/*
���簢�� ����� �� �ټ� ������ �����̰� �ִ�. �������� ũ��� 1��1, 2��2, 3��3, 4��4, 5��5�� �� �ټ� ������ ������, �� ������ �����̴� 5���� ������ �ִ�.
�����̸� ũ�Ⱑ 10��10�� ���� ���� ���̷��� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� 0 �Ǵ� 1�� ���� �ִ�. 1�� ���� ĭ�� ��� �����̷� �������� �Ѵ�. �����̸� ���� ���� ������ ��� ������ �������� �ȵǰ�, ���ĵ� �� �ȴ�. ��, ĭ�� ���� ��ġ�ϰ� �ٿ��� �Ѵ�. 0�� ���� ĭ���� �����̰� ������ �� �ȴ�.

���̰� �־����� ��, 1�� ���� ��� ĭ�� ���̴µ� �ʿ��� �������� �ּ� ������ ���غ���.**/

// ���� ���� ���
// �ּ� ���� ���� ���
// ū�ͺ��� ���ʴ�� ���̸� �ȵȴ�.

//backtracking
//bruteforce

//����?�� ����� ��������.

int paper[6] = { 5,5,5,5,5,5 };
int map[10][10] = { 0 };
bool check[10][10] = { false };
int answer = 987654321;
void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool can_attach(int x ,int y, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[x + i][y + j] == 0)return false;
		}
	}
	return true;
}
void attach(int x, int y, int size,bool can) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[x + i][y + j] = can;
		}
	}
}
int cnt = 0;
void dfs(int x , int y, int n) {
	//�߿��� ������ �ϳ�
	//dfs�� �ϵ� �� �������� ��ӵǴ� ����Ž��
	//print();

	while (map[x][y]!=1) {
		if (y != 9)++y;
		else {
			y = 0;
			++x;
		}
		if (x == 10 && y == 0) {
			answer = min(answer, n);
			return;
		}
	}
	//�����̸� ���̴ٰ� ����Ž���� ���� update�� answer �� ���� ���̰� �ִ� �������� ������ ���غ��� ���� ���̰� �ִ� �������� ������ answer�� ���ų� Ŀ���� ���̻� �������� �ʴ´�. (����ġ��)
	if (answer <= n)return;
	for (int i = 1; i <= 5; i++) {
		if (x + i < 0 || y + i < 0 || x + i >10 || y + i>10 || paper[i]==0)continue;
		if (can_attach(x, y, i)) {
			attach(x, y, i, 0);
			paper[i]--;
			dfs(x, y, n + 1);
			attach(x, y, i, 1);
			paper[i]++;
		}
	}
}
int main() {
	int a = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a;
			map[i][j] = a;
		}
	}
	dfs(0, 0, 0);
	if (answer == 987654321)cout << -1;
	else cout << answer;
	return 0;
}
