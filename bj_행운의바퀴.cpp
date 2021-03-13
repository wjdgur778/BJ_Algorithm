#include<iostream>
#include<deque>
#include<vector>
#include<set>
using namespace std;

/*
바퀴에 같은 글자는 두 번 이상 등장하지 않는다. 또, 바퀴는 시계방향으로만 돌아간다. 바퀴 옆에는 화살표가 있는데, 이 화살표는 항상 한 곳을 가리키고 있으며, 돌아가는 동안 가리키는 글자는 바뀌게 된다. 위의 그림에서는 H를 가리키고 있다.

상덕이는 바퀴를 연속해서 K번 돌릴 것이다. 매번 바퀴를 돌릴 때 마다, 상덕이는 화살표가 가리키는 글자가 변하는 횟수와 어떤 글자에서 회전을 멈추었는지를 종이에 적는다.

희원이는 상덕이가 적어놓은 종이를 발견했다. 그 종이를 바탕으로 상덕이가 바퀴에 적은 알파벳을 알아내려고 한다.

상덕이가 종이에 적어놓은 내용과 바퀴의 칸의 수가 주어졌을 때, 바퀴에 적어놓은 알파벳을 알아내는 프로그램을 작성하시오.
*/

set<char> s;
int n, k;
//항상 같은 방향으로 보자
//로직은 쉽다	
//까다로운 예외처리


int main() {
	cin >> n >> k;
	int cur = 0;
	vector<char>vec(n,'a');
	for (int i = 0; i < k; i++) {
		int a;
		char b;
		cin >> a;
		cin >> b;

		cur = (cur + a) % n;
		if (vec[cur]!='a'&&vec[cur] != b) {
			cout << "!";
			return 0;
		}
		vec[cur] = b;
	}
	//중복검사
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != 'a') {
			if (s.find(vec[i]) == s.end())s.insert(vec[i]);
			else {
				cout << "!";
				return 0;
			}
		}
	}


	for (int i = cur; i >= 0; i--) {
		if (vec[i] == 'a')cout << "?";
		else cout << vec[i];
	}
	for (int i = vec.size() - 1; i > cur; i--) {
		if (vec[i] == 'a')cout << "?";
		else cout << vec[i];
	}

	return 0;
}