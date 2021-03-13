#include<iostream>
#include<deque>
#include<string>
using namespace std;

string s;
int n = 0;
int cursor;
deque <char> A;
deque <char> B;
int main()
{

	cin >> s;
	cin >> n;
	// P : 특정문자추가, L : 왼쪽으로, B : 문자삭제, D : 오른쪽으로
	for (int i = 0; i < s.size(); i++)A.push_back(s[i]);
	for (int i = 0; i < n; i++) {
		char order;
		cin >> order;
		if (order == 'P') {
			char a;
			cin >> a;
			A.push_back(a);
		}
		if (order == 'L'&&A.empty()==false) {
			char tmp = A.back();
			A.pop_back();
			B.push_back(tmp);
		}
		if (order == 'D'&&B.empty()==false) {
			char tmp = B.back();
			B.pop_back();
			A.push_back(tmp);
		}
		if (order == 'B' && A.empty() == false) {
			A.pop_back();
		}
	}
	for (int i = 0; i < A.size(); i++)cout << A[i];
	for (int i = B.size()-1; i >=0; i--)cout << B[i];

	return 0;
}