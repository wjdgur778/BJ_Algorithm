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
���̰� N�� ������ �ִ�. ������ 0���� ũ�ų� ����, 9���� �۰ų� ���� ������ ������(+, -, ��)�� �̷���� �ִ�. ������ �켱������ ��� �����ϱ� ������, ������ ����� ���� ���ʿ������� ������� ����ؾ� �Ѵ�. ���� ���, 3+8��7-9��2�� ����� 136�̴�.

���Ŀ� ��ȣ�� �߰��ϸ�, ��ȣ �ȿ� ����ִ� ���� ���� ����ؾ� �Ѵ�. ��, ��ȣ �ȿ��� �����ڰ� �ϳ��� ��� �־�� �Ѵ�. ���� ���, 3+8��7-9��2�� ��ȣ�� 3+(8��7)-(9��2)�� ���� �߰�������, ���� ����� 41�� �ȴ�. ������, ��ø�� ��ȣ�� ����� �� ����. ��, 3+((8��7)-9)��2, 3+((8��7)-(9��2))�� ��� ��ȣ �ȿ� ��ȣ�� �ֱ� ������, �ùٸ� ���� �ƴϴ�.

������ �־����� ��, ��ȣ�� ������ �߰��� ���� �� �ִ� ���� ����� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �߰��ϴ� ��ȣ ������ ������ ������, �߰����� �ʾƵ� �ȴ�.
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
	//��ȣ�� ������
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
	//�ƹ��͵� ���� ������ 

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
