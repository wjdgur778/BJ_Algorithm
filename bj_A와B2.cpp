#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
string s, S;
bool answer;

//brute force
//������ ȭ������ ����;;
//������ ����� ���� �����غ��� �ݺ��Ǵ� ������ ��������


void recursive(string st) {

	if (st.size() == s.size()) {
		if (st == s) {
			answer = true;
			return;
		}
		return;
	}

	if (S[S.size() - 1] == 'A') {
		S.pop_back();
		recursive(S);
		S += 'A';
	}
	if (S[0] == 'B') {
		reverse(S.begin(), S.end());
		S.pop_back();
		recursive(S);
		S += 'B';
		reverse(S.begin(), S.end());
	}
	return;
}

int main() {

	cin >> s;
	cin >> S;
	recursive(S);

	if (answer)cout << 1;
	else cout << 0;
	return 0;
}