#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
int N;
vector<pair<int,int>>vec;
stack <pair<int,int>> st;
vector<int> answer(1000001,-1);
vector<int> m(1000001, 0);

//°ª³Ö±â

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back({ a,i });
		m[a] += 1;
	}
	st.push(vec[0]);
	int cnt = 1;
	bool f = true;
	for (int j=1, i = 1; i < N; i++) {
		while (!st.empty()&&m[st.top().first] < m[vec[i].first]) {
			answer[st.top().second] = vec[i].first;
			st.pop();
		}
		st.push(vec[i]);
	}
	for (int i = 0; i < N; i++) {
		if (i != N - 1)		cout << answer[i] << " ";
		else cout << answer[i];
	}

	return 0;
}