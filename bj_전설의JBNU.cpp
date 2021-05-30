#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int N, M, K;
map<int, int>m1;
map<int, int>m2;;

// 그냥 함수쓰자.. 시간 훨씬 줄어든다.. 생각할 필요도 없고
//map안에도 lower 와 upper가 있다!!!

//하나하나 생각해주자
//차근차근하면 할만 하다!!
//제발..


int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		m1[a] = b;
		m2[-a] = b;
	}
	for (int i = 0; i < M; i++) {
		int keyV;
		cin >> keyV;
		if (keyV == 1) {
			int key, value;
			cin >> key >> value;
			m1[key] = value;
			m2[-key] = value;
		}
		else if (keyV == 2) {
			int key, value;
			cin >> key >> value;
			//의미상 upper
			auto upper = m1.lower_bound(key);
			//의미상 lower
			auto lower = m2.lower_bound(-key);
			if (upper == m1.end()) {
				if (abs(key + lower->first) <= K) {
					lower->second = value;
					m1[-(lower->first)] = value;
				}
				continue;
			}
			else if (lower == m2.end()) {
				if (abs(upper->first-key) <= K) {
					upper->second = value;
					m2[-(upper->first)] = value;
				}
				continue;
			}
			int du = abs(upper->first - key);
			int dl = abs(key + lower->first);
			if (du < dl) {
				if (du <= K) {
					upper->second = value;
					m2[-(upper->first)] = value;
				}
			}
			if (du > dl) {
				if (dl <= K) {
					lower->second = value;
					m1[-(lower->first)] = value;
				}
			}
		}
		else {
			int key;
			cin >> key;
			//의미상 upper
			auto upper = m1.lower_bound(key);
			//의미상 lower
			auto lower = m2.lower_bound(-key);

			if (upper == m1.end()) {
				if (abs(key + lower->first) <= K) {
					cout << lower->second << endl;
				}
				else cout << -1 << endl;
				continue;
			}
			else if (lower == m2.end()) {
				if (abs(upper->first - key) <= K) {
					cout << upper->second << endl;
				}
				else cout << -1 << endl;
				continue;
			}
			int du = upper->first - key;
			int dl = key + lower->first;
			//거리가 같으면..
			if (du == dl) {
				if (upper->first != -lower->first) {
					cout << "?" << endl;
				}
				else {
					cout << upper->second << endl;
				}
			}
			else if (du < dl) {
				if (du <= K) {
					cout << upper->second << endl;
				}
				else cout << -1 << endl;
			}
			else if (du > dl) {
				if (dl <= K) {
					cout << lower->second << endl;
				}
				else cout << -1 << endl;
			}
		}
	}
	return 0;
}