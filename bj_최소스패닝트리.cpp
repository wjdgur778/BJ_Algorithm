#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v;
int e;
vector < pair<int, pair<int, int>>>vec;
vector <int> check(10001, 0);
int answer = 0;

int get_p(int a) {
	if (a == check[a]) return a;
	return check[a] = get_p(check[a]);
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}

	//�������� �߿��ѰͰ����ϴ�.
	for (int i = 1; i <= v; i++)check[i] = i;
	//�������� ����
	sort(vec.begin(), vec.end());

	//�θ� ã�� �θ� ������ ��ŵ
	for (int i = 0; i < e; i++) {
		int a = get_p(vec[i].second.first);
		int b = get_p(vec[i].second.second);
		int c = vec[i].first;
		if (a !=b) {
			if (a < b)check[b] = a;
			else check[a] = b;
			answer += c;
		}
	}
	cout << answer;
	return 0;
}