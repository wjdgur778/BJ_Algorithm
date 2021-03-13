#include<iostream>
#include<vector>
using namespace std;
/*
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
*/
//A,B,C는 모두 2,147,483,647 (int)
int main()
{
	long long A, B, C;
	long long odd = 1;
	cin >> A >> B >> C;
	if (B == 1)cout << A % C;
	else if (B == 2)cout << ((A % C) * (A % C) )% C;
	else {

		while (B > 0) {
			//B => 2개일때
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