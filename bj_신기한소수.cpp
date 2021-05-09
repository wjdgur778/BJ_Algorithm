#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<math.h>
using namespace std;
int N;
set<string>vec;
int sum;
/*수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다. 요즘 수빈이가 가장 관심있어 하는 소수는 7331이다.

7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다. 즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.

수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다. N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.*/

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
	//2,3,5,7 첫 수
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