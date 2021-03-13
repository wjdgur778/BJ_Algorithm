#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int k;
int tmp = 0;
queue<int>q;
// 1 2 3 4 5 6 7 
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)q.push(i);
	cout << "<";
	while (!q.empty()) {
		int tmp = k;
		for (int i = 0; i < k; i++) {
			int f = q.front();
	
			if (i == k - 1) {
				if (q.size() != 1)cout << f << ", ";
				else cout << f;
				q.pop();
				break;
			}
			q.pop();
			q.push(f);
		}
		
	}
	cout << ">";


	return 0;
}