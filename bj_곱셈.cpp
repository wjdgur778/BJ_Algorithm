#include<iostream>
#include<vector>
using namespace std;
/*
�ڿ��� A�� B�� ���� ���� �˰� �ʹ�. �� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
//A,B,C�� ��� 2,147,483,647 (int)
int main()
{
	long long A, B, C;
	long long odd = 1;
	cin >> A >> B >> C;
	if (B == 1)cout << A % C;
	else if (B == 2)cout << ((A % C) * (A % C) )% C;
	else {

		while (B > 0) {
			//B => 2���϶�
			if (B % 2 == 0) {
				A = ((A % C) * (A % C)) % C;
			}
			else {
				if (B == 1) {
					A = ((A % C) * (odd % C)) % C;
				}
				else {
					odd = ((A % C) * (odd % C)) % C;
					A = ((A % C) * (A % C)) % C;
				}
			}
		
			B /= 2;
		}
		cout << A % C;
	}

	return 0;
}