#include<iostream>
#include<vector>
using namespace std;

int N, M;

//�Ҽ����� �յ��ϰ� �򰡿��鿡�� ��������
//�Ҽ����� �Ϸķ� �����Ͽ� �׳� �򰡿� �ο� ��ŭ ���������� �Ǵ°� �ƴұ�?
//���� �½��ϴ�
//�ڵ带 ©�� �м��� ����Ҽ� ������ �̸� �ٸ��� �� ǥ���Ҽ� �ִ��ĸ� �����ϰ� �ִµ� �ϴ�.
int main() {
	int cnt = 1;
	int answer = 0;
	cin >> N >> M;
	
	while (((cnt * N) / M) != N  ) {
		//cout << (cnt * N) / M << endl;
		if ((cnt * N) % M == 0) {
			int nothing = 0;
			cnt++;
		}
		else {
			answer++;
			cnt++;
		}
		
	}
	cout << answer;
	return 0;
}