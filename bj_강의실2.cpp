//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
//vector<pair<pair<int, int>, int>>vec;
//vector<pair<pair<int, int>, int>>tmp;
//time_t s, e;
//int answer[100001];
//int n;
//int cnt = 1;
//
////���� ��ȣ (1 ~ N) ������� �̿� �ش��ϴ� ���ǽ� ��ȣ�� ��������..!!!
////���� �ð��� ��ġ�� �ʰ�
////�̾�鼭
////�̾�� ���Ѵٸ� ���ǽ��� �����ִ¹������ �غ���
//
//void solution() {
//	pq.push({ vec[0].first.second,{vec[0].second,0} });
//	for (int i = 1; i < vec.size(); i++) {
//		pair<int, pair<int, int>>top = pq.top();
//
//		if (vec[i].first.first < top.first) {
//			pq.push({ vec[i].first.second,{vec[i].second,0} });
//		}
//		else {
//			if (top.second.second == 0) {
//				answer[vec[i].second] = cnt;
//				answer[top.second.first] = cnt;
//				pq.pop();
//				pq.push({ vec[i].first.second,{vec[i].second,cnt++} });
//			}
//			else {
//				answer[vec[i].second] = top.second.second;
//				pq.pop();
//				pq.push({ vec[i].first.second,{vec[i].second,top.second.second} });
//			}
//		}
//	}
//	cout << pq.size() << endl;
//}
//int main() {
//	int a, b, c;
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d %d %d", &a, &b, &c);
//		vec.push_back({ { b,c }, a });
//	}
//	
//	sort(vec.begin(), vec.end());
//	solution();
//	int tmp = cnt;
//	
//	for (int i = 1; i <= pq.size(); i++) {
//		if (answer[i] != 0) {
//			cout << answer[i] << endl;
//		}
//		else {
//			cout << tmp++ << endl;
//		}
//	}
//
//	return 0;
//}

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

pair<int, int> s[100002], e[100002];
int n;
int answer[100001];
//��� ���Ķ����� ����ؼ� �ð��ʰ��� ���� ..
// (cin,cout)�� scanf,printf���� ���� ���� printf������ \n�� endl�� ���̰� ���� ���°��ΰ�? 


int main() {
	cin >> n;
	int tmp = 0;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		s[i] = { b,a };
		e[i] = { c,a };
	}
	sort(s, s + n);
	sort(e, e + n);
	int cnt = 1;
	int s_i = 0;
	int e_i = 0;
	while (s_i<n) {
		if (e[e_i].first<= s[s_i].first) {
			answer[s[s_i].second] = answer[e[e_i].second];
			e_i++;
			s_i++;
		}
		else {
			answer[s[s_i].second] = cnt++;
			tmp++;
			s_i++;
		}
	}
	cout << tmp << endl;
	for (int i = 1; i <= n; i++)cout << answer[i] << '\n';
	return 0;
}

