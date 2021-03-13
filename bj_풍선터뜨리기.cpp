#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int n;
vector<int>answer;
deque<pair<int,int>>dq;

//풍선터뜨리기
//자료구조
//deque이용
//소름 헷갈림
//좋은 코드를 보고싶은 문제

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		dq.push_back({ i + 1,a });
	}
	pair<int, int> cur = { dq.front() };
	dq.pop_front();

	while (!dq.empty()) {

		answer.push_back(cur.first);
		if (dq.size() == 1) {
			answer.push_back(dq.front().first);
			break;
		}
		//0보다 크면 앞에서 뒤로
		if (cur.second > 0) {

			for (int i = 0; i < cur.second-1; i++) {
				pair<int, int>tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
			cur = dq.front();
			dq.pop_front();
		}
		//0보다 작으면 뒤에서 앞으로
		else {
			for (int i = 0; i < abs(cur.second)-1; i++) {
				pair<int, int>tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
			cur = dq.back();
			dq.pop_back();
		}
	}
	for (int i = 0; i < answer.size(); i++)cout << answer[i] << " ";

	return 0;

}