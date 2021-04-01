#include<iostream>
#include<vector>
using namespace std;
long long X;
long long Y;
long long Z;

//binary search
//변화가 있는 순간을 기준점으로 두는 binary search를 한다.

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

		//변화가 있으면 줄여봐(최소값을 구하느거잖아)
		if (abs(Z - tmp )> 0) {
			answer = answer > mid ? mid : answer;
			e = mid - 1;
		}
		//변화가 없음(늘려서 변화를 추구)
		else {
			s = mid + 1;
		}

	}
	if (answer == 1000000010)cout << -1;
	else cout << answer;
	return 0;
}