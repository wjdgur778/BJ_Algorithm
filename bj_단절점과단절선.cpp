#include<iostream>
#include<vector>
using namespace std;
int N,q;
vector<int>vec[100001];

//�������� ������

int main() {

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		//������
		if (a == 1) {
			if (vec[b].size() == 1)cout << "no"<<'\n';
			else cout << "yes"<<'\n';
		}
		//������
		else {
			cout << "yes" << '\n';
		}
	}
	return 0;
}