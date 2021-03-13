#include<iostream>
#include<vector>
using namespace std;

int N, M;

//소세지를 균등하게 평가원들에게 나눠주자
//소세지를 일렬로 나열하여 그냥 평가원 인원 만큼 나눠버리면 되는거 아닐까?
//음음 맞습니다
//코드를 짤때 분수를 사용할수 없으니 이를 다르게 잘 표현할수 있느냐를 질문하고 있는듯 하다.
int main() {
	int cnt = 1;
	int answer = 0;
	cin >> N >> M;
	
	while (((cnt * N) / M) != N  ) {
		//cout << (cnt * N) / M << endl;
		if ((cnt * N) % M == 0) {
			int nothing = 0;
			cnt++;
		}
		else {
			answer++;
			cnt++;
		}
		
	}
	cout << answer;
	return 0;
}