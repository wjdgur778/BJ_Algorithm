#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
���� �ƴ� ������ ���������� ǥ������ ��, ���ʿ������� �ڸ����� ������ ��, �� ���� �پ��� ���ڶ�� �Ѵ�. ���� ���, 321�� 950�� �پ��� �����̰�, 322�� 958�� �ƴϴ�.

N��°�� ���� �پ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� �׷��� ���� ���� ���� -1�� ����Ѵ�. (���� ���� �پ��� ���� 1��° ���� �پ��� ���̴�.)
*/

//1�� ���� 10�� ��� �̾ƺ��� ����Ǽ��� ��� ã�´�.
//��û Ʋ�� ����
//����� ������ -1 �� ����϶�� ������ ��� ������Ű�� ����
//���Ƿ� ũ�⸦ ���� -1�� ����Ϸ��� �ؼ� ������ �Ǿ���.
//�ܼ��� N�� ũ�Ⱑ vec�� ũ�⸦ ����ԵǸ� -1�� ����ϰ� �ؾ��Ѵ�.

int N;
vector<long long>vec;
void dfs(string num) {
	if (num.size() > 0) {
		//cout << num << endl;
		vec.push_back(stoll(num));
	}
	//1 ������ 10 �� �̱�
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