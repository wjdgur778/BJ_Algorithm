#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> vec;
vector<int> dp(200, 1);
// LIS
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for (int i = 1; i < N; i++) {
        bool f = false;
        for (int j = 0; j < i; j++) {
            if (vec[i] > vec[j]) {
                f= true;
                dp[i] = dp[i] < dp[j] ? dp[j] : dp[i];
            }
        }
        if (f)dp[i] += 1;
    }
    int answer = N;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        cout << dp[i] << " ";
        if (tmp <= dp[i])tmp = dp[i];
    }
    answer -= tmp;
    cout << answer;
    return 0;
}