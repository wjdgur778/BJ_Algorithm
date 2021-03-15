#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long>A, B, C, D;
vector<long long >vec_1, vec_2;
int N;
long long answer = 0;

/*
정수로 이루어진 크기가 같은 배열 A, B, C, D가 있다.

A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.

*/

//이분탐색
//메모리가 너무커서 두려움
//중복에 대한 처리도 중요하다.

int b_search(long long n) {
	int out=0;
	int s = 0;
	int e = vec_2.size() - 1; 
	while (s <= e) {
		int mid = (s + e) / 2;
		long long tmp = (n + vec_2[mid]);
		if (tmp < 0) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	out += s;
	s = 0;
	e = vec_2.size() - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		long long tmp = (n + vec_2[mid]);
		if (tmp <= 0) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	out = s - out;
	return out;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vec_1.push_back(A[i] + B[j]);
			vec_2.push_back(C[i] + D[j]);
		}
	}
	sort(vec_2.begin(), vec_2.end());

	for (int i = 0; i < vec_1.size(); i++) {
		answer += b_search(vec_1[i]);
	}
	cout << answer;

	return 0;
}