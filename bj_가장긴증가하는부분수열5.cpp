#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
20
2 54 77 21 14 32 68 47 22 10 6 85 77 85 111 140 25 43 31 11
*/
int N;
int answer = 0;
vector<long long>A; 
vector<long long>ans;
vector<int>dp(1000001,1);
vector<int>index;
/*
LIS�� �ִ� ���̸� ���ϸ� ��Ȯ�� ���� �迭�� �˼� ����.
lower_bound()�Լ��� ����(�̺�Ž�����) �迭�� ���ġ ��Ű�鼭 
��ġ�Ǿ��� �ڸ��� ����ذ���.
����� �ڸ��� �������� ã�ư� ������ ã�´�.
���� �ݷʵ�� �������� ���� "����"�� �ش��� ã�Ҵ�.
lower_bound() ���� �̺�Ž���˰��� �з��� ���� �˾Ҵ�.
�̺�Ž�����ε� ���� �����ϴ�.
*/
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0; 
		cin >> a;
		A.push_back(a);
	}
	ans.push_back(A[0]);
	index.push_back(0);
	for (int i = 1; i < N; i++) {
		if (ans[ans.size() - 1] < A[i]) {
			ans.push_back(A[i]);
			dp[i] = ans.size();
			index.push_back(ans.size()-1);
		}
		else { 
			int idx = 0;
			idx = lower_bound(ans.begin(), ans.end(), A[i]) - ans.begin();
			ans[idx] = A[i];
			index.push_back(idx);
		}
	}

	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;

	vector<long long>tmp;
	for (int i = N - 1; i >= 0; i--) {
		if (index[i] == answer - 1) {
			tmp.push_back(A[i]);
			answer--;
		}
	}
	for (int i = 0; i < index.size(); i++) {
		cout << index[i] << " ";
	}
	cout << endl;
	for (int i = tmp.size() - 1; i >= 0; i--) cout << tmp[i] << " ";
		return 0;
}