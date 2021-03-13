#include<iostream>
#include<string>
#include<vector>
using namespace std;

//A : adaabc B : aababbc	
//최대한 B와 비슷하거나 혹은 같은 문자열이 되려면 어떻게 해야할까?
//A의 앞뒤로 char를 추가할수있다.
//이때의 차이를 출력

int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	int dif=50;
	for (int i = 0; i <=b.size()-a.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (b[i + j] != a[j])cnt++;
		}
		dif = dif >= cnt ? cnt : dif;
	}
	cout << dif;
	return 0;
}