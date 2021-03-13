//#include<iostream>
//#include<vector>
//#include<queue>
//#include<deque>
//#include<map>
//#include<algorithm>
//using namespace std;
//int T;
///*입력 데이터는 표준입력을 사용한다. 입력은 T개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)가 주어진다. 이어지는 k 줄 각각엔 연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n이 주어진다. ‘I n’은 정수 n을 Q에 삽입하는 연산을 의미한다. 동일한 정수가 삽입될 수 있음을 참고하기 바란다. ‘D 1’는 Q에서 최댓값을 삭제하는 연산을 의미하며, ‘D -1’는 Q 에서 최솟값을 삭제하는 연산을 의미한다. 최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨을 유념하기 바란다.
//
//만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시해도 좋다. Q에 저장될 모든 정수는 32-비트 정수이다. */

//1. 자료구조의파악
//1_1.map을 사용하고 이를 iter로 돌리자 사실 여러가지 방법이 있을거같지만..

//reverse_iterator사용...


//int main() {
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		int n;
//		int cnt = 0;
//		cin >> n;
//		map<int, int>m;
//		priority_queue<int, vector<int>, greater<int>>l_pq;
//		priority_queue<int, vector<int>, less<int>>g_pq;
//		
//		for (int j = 0; j < n; j++) {
//			char a;
//			int b;
//			cin >> a;
//			cin >> b;
//			if (a == 'I') {
//				g_pq.push(b);
//				l_pq.push(b);
//				cnt++;
//			}
//			else {
//				if (cnt == 0) {
//					while (!g_pq.empty())g_pq.pop();
//					while (!l_pq.empty())l_pq.pop();
//					continue;
//				}
//				if (b == 1) {
//					g_pq.pop();
//					cnt--;
//				}
//				else{
//					l_pq.pop();
//					cnt--;
//				}
//			}
//		}
//		
//		if (cnt == 0)cout << "EMPTY" << '\n';
//		//else if (cnt == 1)cout << g_pq.top() << " " << g_pq.top() << '\n';
//		else {
//			if (l_pq.empty()) {
//				if (!g_pq.empty()) {
//					int l = 0, g = 0;
//					l = g_pq.top();
//					while (g_pq.size() == 2)g_pq.pop();
//					g = g_pq.top();
//					cout << g << " " << l << '\n';
//				}
//			}
//			else {
//				if (g_pq.empty()) {
//					cout << l_pq.top() << " ";
//					while (l_pq.size() == 2)l_pq.pop();
//					cout << l_pq.top() << '\n';
//				}
//				else {
//					cout << g_pq.top() << " " << l_pq.top()<< '\n';
//				}
//			}
//		}
//	}
//	return 0;
//}

/*
1
7
I 10
I 20
D 1
I 30
I 40
D -1
D -1*/

#include<iostream>
#include<queue>
#include<map>
#include<stack>
using namespace std;
 
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		//g_pq가 메인
		priority_queue<int, vector<int>, greater<int>>g_pq;
		priority_queue<int, vector<int>, less<int>>l_pq;
		map<int, int>m;
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			char a;
			int b;
			cin >> a >> b;
			if (a == 'I') {
				g_pq.push(b);
				l_pq.push(b);
				cnt++;
				if (m.find(b) != m.end())m[b]++;
				else m[b] = 1;
			}
			else {
				
				if (b == 1) {
					while (!l_pq.empty()&&m[l_pq.top()] == 0) {
						l_pq.pop();
					}
					if (l_pq.empty())continue;
					m[l_pq.top()]--;
					l_pq.pop();
					cnt--;
				}
				else {
					while (!g_pq.empty()&&m[g_pq.top()] == 0) {
						g_pq.pop();
					}
					if (g_pq.empty())continue;
					m[g_pq.top()]--;
					g_pq.pop();
					cnt--;
				}
			}
		}
		if (cnt == 0)cout << "EMPTY" << '\n';
		else {
			if (g_pq.size() == 1)cout << g_pq.top() << " " << g_pq.top()<<'\n';
			else {

				map<int, int>::reverse_iterator riter;

				for (riter = m.rbegin(); riter != m.rend(); ++riter) {
					if (riter->second) {
						cout << riter->first<<" ";
						break;
					}
				}
				map<int, int>::iterator iter;

				for (iter = m.begin(); iter != m.end(); iter++) {
					if (iter->second) {
						cout << iter->first <<'\n';
						break;
					}
				}
			}
		}

	}
	return 0;
}