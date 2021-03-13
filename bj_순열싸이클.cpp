#include<iostream>
#include<vector>
using namespace std;

int t;
vector<int>answer;
vector<int> cycle;
vector<bool>check(1001, false);
void do_cycle(int s,int n){
	if (s == cycle[n])return;
	else {
		if (check[cycle[n]] == false) {
			check[cycle[n]] = true;
			do_cycle(s, cycle[n]);
		}
	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int>tmp;
		cycle = tmp;
		cycle.push_back(-1);
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			cycle.push_back(a);
		}
		vector<bool>t(1001, false);
		check = t;
		int cnt = 0;
		//logic
		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				check[i] = true;
				do_cycle(i,i);
				cnt++;
			}
		}
		cout << cnt << endl;;
	}

	return 0;
}