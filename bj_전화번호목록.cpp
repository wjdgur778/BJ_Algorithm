//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//int t, n;
//
//string check(vector<string> s) {
//	int size = s[0].size();
//	int k = 0;
//	while (k<n&&s[k].size() == size) {
//		for (int kk = k + 1; kk < n; kk++) {
//			if (s[kk].size() == size)continue;
//			else {
//				if (s[k] == s[kk].substr(0,size)) {
//					return "NO";
//				}
//			}
//		}
//		k++;
//	}
//	return "YES";
//}
//
//bool comp(string a, string b) {
//	if (a.size() < b.size()) {
//		return true;
//	}
//	else return false;
//}
//int main()
//{
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> n;
//		vector<string>s;
//		//init
//		for (int j = 0; j < n; j++) {
//			string a;
//			cin >> a;
//			s.push_back(a);
//		}
//		sort(s.begin(), s.end(), comp);
//		cout << check(s);
//		if(i!=t-1)cout<< endl;
//	}
//
//
//	return 0;
//
//}