#include<iostream>
#include<vector>
using namespace std;

int S;
int C;
vector<int>vec;
int main() {
	cin >> S >> C;
	int s = 1;
	int e = 1000000001;
	long long  total = 0;
	for (int i = 0; i < S; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
		total += a;
	}

	// C�� Ÿ��
	long long answer=0;
	long long mid;
	while (s <= e) {
		mid = (s + e) / 2;
		long long sum = 0;
		long long ramen = 0;
		cout << mid << endl;
		for (int i = 0; i < vec.size(); i++) {
			sum += (vec[i] / mid);
		}
		if (sum>= C) {
			s = mid + 1;
			//�ٵ� �̰� ���������� ramen�� �� ���ϸ� �ȵǴ� ������ �ӿ���?
			// �׳�
			cout << "operationc " << endl;
			answer = mid;
		}
		else {
			if (s == e)cout << "sldkfj";
			e = mid - 1;
		}
	}
	cout << total - (answer*C) ;
	return 0;
}