#include<iostream>
#include<vector>
#include<string>
using namespace std;
int T;
int n;

/*1부터 N까지의 수를 오름차순으로 쓴 수열 1 2 3 ... N을 생각하자.

그리고 '+'나 '-', 또는 ' '(공백)을 숫자 사이에 삽입하자(+는 더하기, -는 빼기, 공백은 숫자를 이어 붙이는 것을 뜻한다). 이렇게 만든 수식의 값을 계산하고 그 결과가 0이 될 수 있는지를 살피자.





N이 주어졌을 때 수식의 결과가 0이 되는 모든 수식을 찾는 프로그램을 작성하라.*/
// 5 -> 1 2 3 4 5
//더하거나 빼거나 잇거나해서 0을 만들어라
// 1 2 3 4 5
// 1 + 2 3 4 - 5
// 1 2 - 3 - 4 - 5
//1 + 2 + 3 + 4 + 5
void solution(int sign,int s,int e,int sum,string st) {
	if (e == n) {
		sum += (s * sign);
		if (sum == 0) {
			cout << st << endl;
			return;
		}
		else return;
	}
	//key-point는 계산을 할때 이전의 값들을 계산하는것!
	//연산을 바로바로 처리하면 공백을 처리할 수가 없음
	//연산을 만나면 이전 연산을 해준다는 로직
	//공백때는 모든것을 그대로 두고 숫자를 붙여주기만 한다.

	solution(sign,s * 10 + e+1, e + 1, sum, st + " " + to_string(e+1));
	// " + " 와 " - "에서의 prev는 reset 되어야 한다.
	solution(1,e+1,e+1,sum+s*sign,st+"+"+to_string(e+1));
	solution(-1, e + 1, e + 1, sum + s * sign, st + "-" + to_string(e + 1));
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		solution(1,1, 1 ,0,"1");
		cout << endl;
	}
	return 0;
}