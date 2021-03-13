#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
음이 아닌 정수를 십진법으로 표기했을 때, 왼쪽에서부터 자리수가 감소할 때, 그 수를 줄어드는 숫자라고 한다. 예를 들어, 321와 950은 줄어드는 숫자이고, 322와 958은 아니다.

N번째로 작은 줄어드는 수를 출력하는 프로그램을 작성하시오. 만약 그러한 수가 없을 때는 -1을 출력한다. (가장 작은 줄어드는 수가 1번째 작은 줄어드는 수이다.)
*/

//1개 부터 10개 모두 뽑아보는 경우의수를 모두 찾는다.
//엄청 틀린 문제
//만들수 없을때 -1 을 출력하라는 조건을 계속 만족시키지 못함
//임의로 크기를 정해 -1을 출력하려고 해서 문제가 되었다.
//단순히 N의 크기가 vec의 크기를 벗어나게되면 -1을 출력하게 해야한다.

int N;
vector<long long>vec;
void dfs(string num) {
	if (num.size() > 0) {
		//cout << num << endl;
		vec.push_back(stoll(num));
	}
	//1 개부터 10 개 뽑기
	for (int i = 0; i <= 9; i++) {
		if (num.size() == 0)dfs(to_string(i));
		if (num.size()!=0&&num.back()-'0' >i) {
			dfs(num + to_string(i));
		}
	}
}
int main()
{
	cin >> N;
		dfs("");
		sort(vec.begin(), vec.end());
		//cout << vec.size() << endl;
		if (N > vec.size())cout << -1;
		else cout << vec[N-1];
	
	return 0;
}