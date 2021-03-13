#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// https://www.acmicpc.net/problem/17136

/*
정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.
색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다. 1이 적힌 칸은 모두 색종이로 덮여져야 한다. 색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 겹쳐도 안 된다. 또, 칸의 경계와 일치하게 붙여야 한다. 0이 적힌 칸에는 색종이가 있으면 안 된다.

종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.**/

// 종이 갯수 고려
// 최소 갯수 임을 명심
// 큰것부터 차례대로 붙이면 안된다.

//backtracking
//bruteforce

//구현?에 가까운 문제같다.

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
	//중요한 로직중 하나
	//dfs를 하되 그 순간마다 계속되는 완전탐색
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
	//색종이를 붙이다가 완전탐색이 끝나 update된 answer 과 현재 붙이고 있는 색종이의 갯수를 비교해보고 현재 붙이고 있는 색종이의 갯수가 answer과 같거나 커지면 더이상 연산하지 않는다. (가지치기)
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
