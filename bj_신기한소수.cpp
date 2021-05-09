#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<math.h>
using namespace std;
int N;
set<string>vec;
int sum;
/*�����̰� ���󿡼� ���� �����ϴ� ���� �Ҽ��̰�, ��̴� �Ҽ��� ������ ��� ���̴�. ���� �����̰� ���� �����־� �ϴ� �Ҽ��� 7331�̴�.

7331�� �Ҽ��ε�, �ű��ϰԵ� 733�� �Ҽ��̰�, 73�� �Ҽ��̰�, 7�� �Ҽ��̴�. ��, ���ʺ��� 1�ڸ�, 2�ڸ�, 3�ڸ�, 4�ڸ� �� ��� �Ҽ��̴�! �����̴� �̷� ���ڸ� �ű��� �Ҽ���� �̸� �ٿ���.

�����̴� N�ڸ��� ���� �߿��� � ������ �ű��� �Ҽ����� �ñ�������. N�� �־����� ��, �����̸� ���� N�ڸ� �ű��� �Ҽ��� ��� ã�ƺ���.*/

void find(int n,int idx) {
	
	if (idx == N) {
		cout << n << "\n";
		return;
	}

	for (int i = 1; i < 10; i++) {
		int tmp = n * 10 + i;
		bool f = true;
		for (int j = 2; j <= sqrt(tmp); j++) {
			if (tmp % j == 0)f = false;
		}
		if (f)find(tmp,idx+1);
	}
	return;
}

int main() {
	cin >> N;
	//2,3,5,7 ù ��
	if (N == 1) {
		cout << 2 << "\n";
		cout << 3 << "\n";
		cout << 5 << "\n";
		cout << 7 << "\n";
	}
	else {
		find(2, 1);
		find(3, 1);
		find(5, 1);
		find(7, 1);
	}


	return 0 ;
}