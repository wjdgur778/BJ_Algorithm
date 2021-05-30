#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, k;
		long long sum = 0;
		vector<int>vec;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			vec.push_back(a);
		}
		//logic
		//���� �ٸ� �ΰ��� ������ ���� k�� ���� ������ �ϴ� �������� ����
		// MAX : 1000000
		// �����ϸ鼭 �ּҿ��� ģ������ ��ƶ�
		//��������??
		// 4
		//-7 -4 -3 -2 0 1 2 5 9 12
		//1 3 5 7 9
		// �� ������ ������
		int s = 0;
		int e = vec.size() - 1;
		int target = k;
		long long comp = 9876542311;
		sort(vec.begin(), vec.end());
		int cnt = 0;
		while (s < e) {
			if (k > vec[s] + vec[e]) {
				//�ּҸ� ����
				s++;
			}
			else if (k == vec[s] + vec[e]) {
				s++;
				cnt++;
				e--;
			}
			else e--;
		}

		cout << cnt << "\n";

	}
	return 0;
}