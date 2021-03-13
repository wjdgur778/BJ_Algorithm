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

	// C가 타겟
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
			//근데 이게 나머지들을 ramen에 다 더하면 안되는 이유가 머예여?
			// 네네
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