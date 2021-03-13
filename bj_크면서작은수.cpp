#include<iostream>
#include<vector>
#include<string>

#include<algorithm>
using namespace std;

string n;
string a;
int target;
int answer = 1000000;
vector<bool>check(7, false);

//정석 백트래킹
void dfs(string num,int cnt) {
	if (n.size() == cnt) {
		if (stoi(num) > target) {
			answer = answer >= stoi(num) ? stoi(num) : answer;
		}
	}
	for (int i = 0; i < n.size(); i++) {
		if (check[i] == true)continue;
		check[i] = true;
		num += n[i];
		dfs(num, cnt + 1);
		num.pop_back();
		check[i] = false;
	}
}
int main() {
	cin >> n;
	target = stoi(n);
	dfs("", 0);
	if (answer == 1000000)cout << 0;
	else cout << answer;
	return 0;
}