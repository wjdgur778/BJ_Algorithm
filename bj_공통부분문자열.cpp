#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>>vec(4002, vector<int>(4002,0));
string A;
string B;
//�������̱⶧����
//������� DP�� Ȱ���Ͽ� ������ �밢������ �÷������� �ȴ�.
//���Ҷ� ���� �ٸ��� �����ص��ȴ�//

int main() {	
	cin >> A;
	cin >> B;
	int ans = 0;
	for (int i = 1; i <= A.size(); i++) {

		for (int j = 1; j <= B.size(); j++) {

			if (A[i - 1] == B[j - 1]) {
				vec[i][j] = vec[i - 1][j - 1] + 1;
				if (ans < vec[i][j])ans = vec[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}