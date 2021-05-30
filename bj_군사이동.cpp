#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


//경로 상에 있는 길 중 너비가 가장 좁은 길의 너비를 최대화하는 경로를 택했습니다.

//15 23 16 27 3 21 14 10 50 9 42
// c  -->  v  경로에 포함된 길의 최소값을 최대로 하는것
//Union Find 이용!!!!!!!!!
//길의 너비가 넓은 순서대로 부모를 이어나가면서 c --> v 의 부모가 서로 같은 순간(하나의 그래프상에 c와 v가 있을때) 길의 너비를 출력한다.


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