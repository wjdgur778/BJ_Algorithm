#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


//��� �� �ִ� �� �� �ʺ� ���� ���� ���� �ʺ� �ִ�ȭ�ϴ� ��θ� ���߽��ϴ�.

//15 23 16 27 3 21 14 10 50 9 42
// c  -->  v  ��ο� ���Ե� ���� �ּҰ��� �ִ�� �ϴ°�
//Union Find �̿�!!!!!!!!!
//���� �ʺ� ���� ������� �θ� �̾���鼭 c --> v �� �θ� ���� ���� ����(�ϳ��� �׷����� c�� v�� ������) ���� �ʺ� ����Ѵ�.


int p, w, c, v;
vector < pair<int, pair<int, int>>>vec;
int check[1001];

int get_p(int n) {
	if (check[n] == n)return n;
	else return check[n]=get_p(check[n]);
}

int find(int n) {
	if (check[n] == n)return n;
	else return find(check[n]);
}

bool comp(pair<int,pair<int,int>>a, pair<int,pair<int, int>>b) {
	return a.first > b.first;
}

int main() {
	cin >> p >> w >> c >> v;
	for (int i = 0; i < w; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}
	for (int i = 0; i < p; i++) {
		check[i] = i;
	}
	sort(vec.begin(), vec.end(),comp);
	for (int i = 0; i < vec.size(); i++) {
		int a = get_p(vec[i].second.first);
		int b = get_p(vec[i].second.second);
		if (a != b) {
			if (a < b)check[a] = b;
			else check[b] = a;
		}
		if (find(c)==find(v)) {
			cout << vec[i].first;
			break;
		}
	}
	return 0;
}