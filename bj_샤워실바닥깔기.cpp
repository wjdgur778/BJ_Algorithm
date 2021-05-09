#include<iostream>
#include<vector>
using namespace std;
int k;
pair <int, int> t;
int n=1;
int vec[4][4];
int lx, ly;

/*
오늘은 민규가 훈련소에 입소하는 날이다. 모든 행사를 마치고 생활관으로 돌아와서 쉬려는데 갑자기 교관이 들어오더니 민규의 이름을 부르는 것이 아닌가. 당황한 채로 따라갔더니 이번엔 김준서를 아느냐고 물어보았다. 그 녀석이 샤워실 바닥을 깔았는데, 배수구 위치까지 막아버렸다면서 같은 학교 출신인 민규가 다시 깔라는 것이었다.

어떻게 타일을 깔지 고민하던 민규는 샤워실의 구조가 정사각형이면서 한 변의 길이가 2의 제곱수라는 사실을 알아냈다. 준서는 여기까지만 고려해서 2x2 크기의 타일로 바닥을 전부 채운 것 같은데, 문제는 이렇게 하면 배수구가 있어야 할 위치를 비울 수가 없다는 것이다. 이런저런 방법을 생각하다가 4칸을 차지하는 정사각형 타일 대신 3칸을 차지하는 ㄱ자 모양의 타일을 사용하면 될 것 같다는 느낌을 받았다.

그런데 ㄱ자 타일을 어떻게 채워야 할까? 생각하다 지친 민규는 여러분에게 이 방법을 찾아달라고 부탁했다. 첫날부터 생활관에서 밤을 새우는 일이 없도록 여러분이 도와주자.
*/

//Divide & Conquer
//근데 이게 왜 분할정복일까?
//의논하고싶다.

bool check(int x, int y) {
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			if (i == 2 * k - t.second && j == t.first - 1) {
				lx = x;
				ly = y;
				return false;
			}
		}
	}
	return true;
}
void attach(int x,int y) {
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			vec[i][j] = n;
		}
	}
	n++;
	return;
}
int main() {
	cin >> k;
	cin >> t.first >> t.second;
	if (k == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == 2 * k - t.second && j == t.first - 1) {
					cout << -1 << " ";
				}
				else cout << 1 << " ";
			}
			if(i!=1) cout << endl;
		}
	}
	else {
		for (int i = 0; i < 4; i += 2) {
			for (int j = 0; j < 4; j += 2) {
				if (check(i, j)) {
					attach(i, j);
				}
			}
		}
		attach(1, 1);
		attach(lx, ly);
		vec[2 * k - t.second][t.first - 1]=-1;
		for (int i = 0; i < 2 * k; i++) {
			for (int j = 0; j < 2 * k; j++) {
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}