	//#include<iostream>
	//#include<vector>
	//#include<string>
	//#include<queue>
	//using namespace std;
	//
	//// 그리디로 풀면 안풀림
	//
	//int main() {
	//	string s;
	//
	//	int k;
	//	cin >> s;
	//	cin >> k;
	//	int result = stoi(s);
	//	string n = s;
	//	bool f = true;
	//	int a, b;
	//	int cnt = 0;
	//	for (int i = 0; i < s.size(); i++) {
	//		if (s[i] != '0')cnt++;
	//	}
	//	if (cnt == 1) {
	//		cout << -1;
	//		return 0;
	//	}
	//	while (k != 0) {
	//		priority_queue<int,vector<int>>pq;
	//		for (int i = 0; i < s.size() - 1; i++) {
	//			for (int j = i + 1; j < s.size(); j++) {
	//				if (s[i] == 0) continue;
	//				if (s[j] == 0) continue;
	//				n = s;
	//				//swap
	//				char a = n[j];
	//				n[j] = n[i];
	//				n[i] = a;
	//				pq.push(stoi(n));
	//				
	//			}
	//		}
	//		
	//		s = to_string(pq.top());
	//		//cout << s << endl;
	//		k--;
	//	}
	//	cout << s;
	//
	//	return 0;
	//}

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
queue<string>q;
//bfs 탐색문제
int main() {
	string n;
	int answer = 0;
	int k;
	int digits;
	cin >> n;
	cin >> k;
	if (stoi(n) % 10 == 0 && stoi(n) < 100) {
		cout << -1;
		return 0;
	}
	if (n.size() == 1) {
		cout << -1;
		return 0;
	}
	q.push(n);
	int result = 0;


	//해당 level에서의 최댓값
	//마지막 k에 다다르고 나서 최댓값을본다
	//단계별로 check를 갱신해야한다.

	while (!q.empty()&&k>0) {
		int size = q.size();
		set<string>s;
		for (int i = 0; i < size; i++) {
			string num = q.front();
			int n_size = num.size();
			q.pop();

			for (int i = 0; i <n_size-1; i++) {
				for (int j = i+1; j < n_size ; j++) {
					if (i == 0 && num[j] == 0)continue;
					string next=num;
					char a = next[i];
					next[i] = next[j];
					next[j] = a;
					//cout << next << " ";

					if (s.find(next) == s.end()) {

						if (k == 1 && stoi(next) > result) {
							result = stoi(next);
						}
						s.insert(next);
						q.push(next);
					}
				}
			} 
		}
		
		//cout << endl;
		k--;
	}
	
	cout << result;

	return 0;
}
