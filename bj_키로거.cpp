#include<iostream>
#include<string>
#include<deque>
#include<vector>
using namespace std;

int t;
int main() {

	cin >> t;
	for (int i = 0; i < t; i++) {
		string a = "";
		deque<char>f_dq;
		deque<char>s_dq;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (!f_dq.empty() && s[i] == '<') {
				s_dq.push_front(f_dq.back());
				f_dq.pop_back();
			}
			if (!s_dq.empty() && s[i] == '>') {
				f_dq.push_back(s_dq.front());
				s_dq.pop_front();
			}
			if (s[i] != '>' && s[i] != '<' && s[i] != '-') {
				f_dq.push_back(s[i]);
			}
			if( s[i] == '-') {
				if (!f_dq.empty())f_dq.pop_back();
				else continue;
			}
		}

		for (int i = 0; i < f_dq.size(); i++) {
			cout << f_dq[i];
		}
		for (int i = 0; i < s_dq.size(); i++) {
			cout << s_dq[i];
		}
		cout << endl;
	}
	return 0;

}