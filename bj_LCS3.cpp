#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string a;
string b;
string c;
int vec[101][101][101] = { 0 };
int main() {
	int ans = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			for (int k = 1; k <= c.size(); k++) {
			//	cout << a[i - 1] << " " <<b[j-1]<< " " <<c[k-1]<<endl ;
				if (a[i - 1] == b[j - 1]&& b[j - 1] == c[k - 1]) {
				//	cout << "wow";
					vec[i][j][k] = vec[i - 1][j - 1][k - 1] + 1;
					if (ans < vec[i][j][k]) ans = vec[i][j][k];
				}
				else {
					vec[i][j][k] = max(vec[i][j][k - 1], vec[i][j-1][k]);
				}

			}
		}

	}
	cout << ans;
	return 0;
}