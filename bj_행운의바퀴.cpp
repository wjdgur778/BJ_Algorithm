#include<iostream>
#include<deque>
#include<vector>
#include<set>
using namespace std;

/*
������ ���� ���ڴ� �� �� �̻� �������� �ʴ´�. ��, ������ �ð�������θ� ���ư���. ���� ������ ȭ��ǥ�� �ִµ�, �� ȭ��ǥ�� �׻� �� ���� ����Ű�� ������, ���ư��� ���� ����Ű�� ���ڴ� �ٲ�� �ȴ�. ���� �׸������� H�� ����Ű�� �ִ�.

����̴� ������ �����ؼ� K�� ���� ���̴�. �Ź� ������ ���� �� ����, ����̴� ȭ��ǥ�� ����Ű�� ���ڰ� ���ϴ� Ƚ���� � ���ڿ��� ȸ���� ���߾������� ���̿� ���´�.

����̴� ����̰� ������� ���̸� �߰��ߴ�. �� ���̸� �������� ����̰� ������ ���� ���ĺ��� �˾Ƴ����� �Ѵ�.

����̰� ���̿� ������� ����� ������ ĭ�� ���� �־����� ��, ������ ������� ���ĺ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
*/

set<char> s;
int n, k;
//�׻� ���� �������� ����
//������ ����	
//��ٷο� ����ó��


int main() {
	cin >> n >> k;
	int cur = 0;
	vector<char>vec(n,'a');
	for (int i = 0; i < k; i++) {
		int a;
		char b;
		cin >> a;
		cin >> b;

		cur = (cur + a) % n;
		if (vec[cur]!='a'&&vec[cur] != b) {
			cout << "!";
			return 0;
		}
		vec[cur] = b;
	}
	//�ߺ��˻�
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != 'a') {
			if (s.find(vec[i]) == s.end())s.insert(vec[i]);
			else {
				cout << "!";
				return 0;
			}
		}
	}


	for (int i = cur; i >= 0; i--) {
		if (vec[i] == 'a')cout << "?";
		else cout << vec[i];
	}
	for (int i = vec.size() - 1; i > cur; i--) {
		if (vec[i] == 'a')cout << "?";
		else cout << vec[i];
	}

	return 0;
}