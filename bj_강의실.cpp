#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
N개의 강의가 있다. 우리는 모든 강의의 시작하는 시간과 끝나는 시간을 알고 있다. 이때, 우리는 최대한 적은 수의 강의실을 사용하여 모든 강의가 이루어지게 하고 싶다.

물론, 한 강의실에서는 동시에 2개 이상의 강의를 진행할 수 없고, 한 강의의 종료시간과 다른 강의의 시작시간이 겹치는 것은 상관없다. 필요한 최소 강의실의 수를 출력하는 프로그램을 작성하시오.
*/
//가장 빨리 끝나는 수업에 가장 근접하게 시작하는 강의들을 이어 붙여나간다.
//강의를 이어나갈 수 없다면 강의실을 추가한다는 형식
//즉, 가장 빨리 끝나는 수업과 가장 빨리 시작하는 수업을 비교해 나가면서 수업을 이어나간다.
//너어어어무 어려웠다.
//그리디

priority_queue<int>s;
priority_queue<int>e;
int n;
int answer;

int main() {
	cin >> n;
	int a,b,c;
	for (int i = 0; i < n; i++) {
		cin >>a>>b>>c;
		s.push(-b);
		e.push(-c);
	}
	while (!s.empty()) {
		if (-e.top() <= -s.top()) {
			e.pop();
			s.pop();	
		}
		else {
			s.pop();
			answer++;
		}
	}
	cout << answer;
	//for (int i = 0; i < lecture.size(); i++)cout << lecture[i].second << endl;
	return 0;
}

