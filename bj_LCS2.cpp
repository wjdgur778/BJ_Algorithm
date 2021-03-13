#include<iostream>
#include<vector>
#include<string>
using namespace std;
string ans;

int main() {


	vector<vector<int>>vec(1001, vector<int>(1002, 0));
	string A;
	string B;
	int cnt = 0;
	cin >> A;
	cin >> B;
	for (int i = 1; i <= B.size(); i++) {

		for (int j = 1; j <= A.size(); j++) {
			if (A[j - 1] == B[i - 1]) {
				vec[i][j] = vec[i - 1][j - 1] + 1;
				if (cnt < vec[i][j])cnt = vec[i][j];
			}
			else {
				vec[i][j] = vec[i - 1][j] >=vec[i][j-1] ? vec[i-1][j] : vec[i][j-1];
			}
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	int j = B.size();

		for (int i = A.size(); i > 0; i--) {
			while (j>0&&vec[i][j] == vec[i][j - 1]) {
				j--;
			}
			ans = B[--j] + ans;

			if (j <= 0)break;
		}
		if (cnt == 0)cout << cnt;
		else cout <<cnt<<endl<< ans;

	

	return 0;
}