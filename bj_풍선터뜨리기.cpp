#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int n;
vector<int>answer;
deque<pair<int,int>>dq;

//ǳ���Ͷ߸���
//�ڷᱸ��
//deque�̿�
//�Ҹ� �򰥸�
//���� �ڵ带 ������� ����

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
		//0���� ũ�� �տ��� �ڷ�
		if (cur.second > 0) {

			for (int i = 0; i < cur.second-1; i++) {
				pair<int, int>tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
			cur = dq.front();
			dq.pop_front();
		}
		//0���� ������ �ڿ��� ������
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