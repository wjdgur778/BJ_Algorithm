#include<iostream>
#include<vector>
using namespace std;

/*세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.
첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, N2)보다 작거나 같은 자연수이다.
*/

//주의!!! : N * N을 할 당시에 int  값을 벗어나는 (100억)이 되므로 죄다 long long 으로 선언하고 캐스팅까지 해주자...


//이분탐색임을 알지 못하면 풀지도 못했을것..
//그렇다고 이분탐색임을 알고도 잘 푼것도 아니다..
//이분탐색을 어떻게 적용할것인가도 문제이다.
//갯수를 세는것(준 bruteforce)에 두려움이 있었다면 풀지 못했을것이다.
//확실한것은 "극소" 극대"!!! 이 문제는 target이 정확하게 맞는것이 아닌 이상일때도 답이 될수 있다..
// 극소 극대.. 언제 start때 답을 주고 언제 end일때 답을 주어야 하는지 조금은 알겠다.

int main() {
	int N;
	int k;
	cin >> N >> k;
	long long s = 1;
	long long e = (long long)N * (long long)N;
	long long answer=0;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long sum = 0;

		for (int i = 1; i <= N; i++) {
			//포인트
			//본인이 정한 mid보다 아래인 수가 몇개나 있을까를 세는것!
			//이를 하나하나 보면 터진다.
			//division을 이용하자
			sum += mid / i > N ? N : mid / i;
		}
		//cout << " s : "<<s << " " <<" mid : "<<  mid << " " <<" e :  "  << e <<" sum : "<<sum<< endl;
		if (sum < k) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
			answer = mid;
		}
		
	}
	cout << answer;
	return 0;
}