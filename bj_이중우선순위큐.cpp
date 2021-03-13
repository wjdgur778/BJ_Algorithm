//#include<iostream>
//#include<vector>
//#include<queue>
//#include<deque>
//#include<map>
//#include<algorithm>
//using namespace std;
//int T;
///*�Է� �����ʹ� ǥ���Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �����ȴ�. �Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����. �� �׽�Ʈ �������� ù° �ٿ��� Q�� ������ ������ ������ ��Ÿ���� ���� k (k �� 1,000,000)�� �־�����. �̾����� k �� ������ ������ ��Ÿ���� ����(��D�� �Ǵ� ��I��)�� ���� n�� �־�����. ��I n���� ���� n�� Q�� �����ϴ� ������ �ǹ��Ѵ�. ������ ������ ���Ե� �� ������ �����ϱ� �ٶ���. ��D 1���� Q���� �ִ��� �����ϴ� ������ �ǹ��ϸ�, ��D -1���� Q ���� �ּڰ��� �����ϴ� ������ �ǹ��Ѵ�. �ִ�(�ּڰ�)�� �����ϴ� ���꿡�� �ִ�(�ּڰ�)�� �� �̻��� ���, �ϳ��� �������� �����ϱ� �ٶ���.
//
//���� Q�� ����ִµ� ������ ������ ��D����� �� ������ �����ص� ����. Q�� ����� ��� ������ 32-��Ʈ �����̴�. */

//1. �ڷᱸ�����ľ�
//1_1.map�� ����ϰ� �̸� iter�� ������ ��� �������� ����� �����Ű�����..

//reverse_iterator���...


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

		//g_pq�� ����
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