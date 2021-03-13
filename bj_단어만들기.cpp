#include<iostream>
#include<vector>
#include<string>
#include<set>adoctint.h
using namespace std;
vector<string> dict;
vector<string>puzzle;
vector<vector<int>>alpha;
//미완

int main() {

	while (1) {
		string a;
		set<char> s;
		cin >> a;
		if (a == "-")break;
		dict.push_back(a);
	}
	while (1) {
		string a;
		cin >> a;
		if (a == "#")break;
		vector<int>tmp(26, 0);
		for (int i = 0; i < a.size(); i++)tmp[a[i] - 65]++;
		alpha.push_back(tmp);
		puzzle.push_back(a);

	}
	//대문자 A => 65
	for (int i = 0; i < puzzle.size(); i++) {
		vector<int> calc = alpha[i];
		for (int j = 0; j < dict.size(); j++) {


		}


	}

	return 0;
}