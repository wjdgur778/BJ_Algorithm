#include<iostream>
#include<vector>
using namespace std;
long long X;
long long Y;
long long Z;

//binary search
//��ȭ�� �ִ� ������ ���������� �δ� binary search�� �Ѵ�.

int main() {
	cin >> X >> Y;

	Z = (Y * 100) / X;
	long long s = 0;
	long long  e = X;
	long long answer = 1000000010;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long tmp = ((Y + mid) * 100) / (X + mid);
		//cout << mid <<" " <<Z<<" "<<tmp<<endl;

		//��ȭ�� ������ �ٿ���(�ּҰ��� ���ϴ����ݾ�)
		if (abs(Z - tmp )> 0) {
			answer = answer > mid ? mid : answer;
			e = mid - 1;
		}
		//��ȭ�� ����(�÷��� ��ȭ�� �߱�)
		else {
			s = mid + 1;
		}

	}
	if (answer == 1000000010)cout << -1;
	else cout << answer;
	return 0;
}