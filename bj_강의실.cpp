#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
N���� ���ǰ� �ִ�. �츮�� ��� ������ �����ϴ� �ð��� ������ �ð��� �˰� �ִ�. �̶�, �츮�� �ִ��� ���� ���� ���ǽ��� ����Ͽ� ��� ���ǰ� �̷������ �ϰ� �ʹ�.

����, �� ���ǽǿ����� ���ÿ� 2�� �̻��� ���Ǹ� ������ �� ����, �� ������ ����ð��� �ٸ� ������ ���۽ð��� ��ġ�� ���� �������. �ʿ��� �ּ� ���ǽ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
//���� ���� ������ ������ ���� �����ϰ� �����ϴ� ���ǵ��� �̾� �ٿ�������.
//���Ǹ� �̾�� �� ���ٸ� ���ǽ��� �߰��Ѵٴ� ����
//��, ���� ���� ������ ������ ���� ���� �����ϴ� ������ ���� �����鼭 ������ �̾����.
//�ʾ�� �������.
//�׸���

priority_queue<int>s;
priority_queue<int>e;
int n;
int answer;

int main() {
	cin >> n;
	int a,b,c;
	for (int i = 0; i < n; i++) {
		cin >>a>>b>>c;
		s.push(-b);
		e.push(-c);
	}
	while (!s.empty()) {
		if (-e.top() <= -s.top()) {
			e.pop();
			s.pop();	
		}
		else {
			s.pop();
			answer++;
		}
	}
	cout << answer;
	//for (int i = 0; i < lecture.size(); i++)cout << lecture[i].second << endl;
	return 0;
}

