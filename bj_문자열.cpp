#include<iostream>
#include<string>
#include<vector>
using namespace std;

//A : adaabc B : aababbc	
//�ִ��� B�� ����ϰų� Ȥ�� ���� ���ڿ��� �Ƿ��� ��� �ؾ��ұ�?
//A�� �յڷ� char�� �߰��Ҽ��ִ�.
//�̶��� ���̸� ���

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