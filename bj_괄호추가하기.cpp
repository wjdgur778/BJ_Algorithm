#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<char>num;
string s;
long long answer=-9876543211;
int n;
/*
길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다. 예를 들어, 3+8×7-9×2의 결과는 136이다.

수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다. 예를 들어, 3+8×7-9×2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다. 하지만, 중첩된 괄호는 사용할 수 없다. 즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.

수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오. 추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.
*/

//brute force

long long calc(long long  a, long long b, char c) {
	if (c == '+')return a + b;
	else if (c == '-')return a - b;
	else return a * b;
}

void dfs(int idx, long long sum) {
	if (idx >= n) {
		answer = answer < sum ? sum : answer;
		//cout << "Answer!!!!!!! " <<answer <<endl;
		return;
	}
	//괄호로 묶을때
	if (idx + 2 < n) {
		if (idx - 1 >= 0) {
			char a = num[idx - 1];
			dfs(idx + 4, calc(sum, calc(num[idx] - '0', num[idx + 2] - '0', num[idx + 1]), a));
		}
		else dfs(idx + 4, calc(num[idx] - '0', num[idx + 2] - '0', num[idx + 1]));
	}
	if(idx-1>=0)dfs(idx + 2, calc(sum, num[idx] - '0', num[idx - 1]));
	else dfs(idx + 2, num[idx]-'0');
	return;
	//아무것도 하지 않을때 

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		num.push_back(a);
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}
