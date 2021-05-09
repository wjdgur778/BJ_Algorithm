#include<iostream>
#include<vector>
#include<string>
using namespace std;
int T;
int n;

/*1���� N������ ���� ������������ �� ���� 1 2 3 ... N�� ��������.

�׸��� '+'�� '-', �Ǵ� ' '(����)�� ���� ���̿� ��������(+�� ���ϱ�, -�� ����, ������ ���ڸ� �̾� ���̴� ���� ���Ѵ�). �̷��� ���� ������ ���� ����ϰ� �� ����� 0�� �� �� �ִ����� ������.





N�� �־����� �� ������ ����� 0�� �Ǵ� ��� ������ ã�� ���α׷��� �ۼ��϶�.*/
// 5 -> 1 2 3 4 5
//���ϰų� ���ų� �հų��ؼ� 0�� ������
// 1 2 3 4 5
// 1 + 2 3 4 - 5
// 1 2 - 3 - 4 - 5
//1 + 2 + 3 + 4 + 5
void solution(int sign,int s,int e,int sum,string st) {
	if (e == n) {
		sum += (s * sign);
		if (sum == 0) {
			cout << st << endl;
			return;
		}
		else return;
	}
	//key-point�� ����� �Ҷ� ������ ������ ����ϴ°�!
	//������ �ٷιٷ� ó���ϸ� ������ ó���� ���� ����
	//������ ������ ���� ������ ���شٴ� ����
	//���鶧�� ������ �״�� �ΰ� ���ڸ� �ٿ��ֱ⸸ �Ѵ�.

	solution(sign,s * 10 + e+1, e + 1, sum, st + " " + to_string(e+1));
	// " + " �� " - "������ prev�� reset �Ǿ�� �Ѵ�.
	solution(1,e+1,e+1,sum+s*sign,st+"+"+to_string(e+1));
	solution(-1, e + 1, e + 1, sum + s * sign, st + "-" + to_string(e + 1));
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		solution(1,1, 1 ,0,"1");
		cout << endl;
	}
	return 0;
}