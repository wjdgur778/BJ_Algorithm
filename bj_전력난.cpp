#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> check;
vector<int>ans_vec;


/*
�����̴� �� ������ �����ε� ������ ���³��� �������. �׷��� ��� �渶�� ���� ���� �ִ� ���ε� �� �Ϻθ� �ҵ��ϱ�� �Ͽ���. ���� ���ε��� �� �θ� �Ϸ翡 ���� ���� ����ŭ ���� ���µ�, �Ϻθ� �ҵ��Ͽ� �׸�ŭ�� ���� ������ �� �ִ�.

�׷��� ���� � �� ���� �շ��� ��, ���� ���� ���� ���� ���� �ݵ�� ������ �Ѵٸ� �����ϴ�. �׷��� ���ÿ� �ִ� ��� �� �� �ֿ� ����, ���� ���� �游���� ���θ� �շ��� �� �־�� �Ѵ�.

�� ������ ��Ű�鼭 ������ �� �ִ� �ִ� �׼��� ���Ͻÿ�.
*/

//text case�� ���� ���� �ָ��ϰ� ������ �ΰ� �϶�°� ���� �ɺ��ε�;;
//�ּ� ���д�Ʈ��
//��� ���д� Ʈ���� �̿��Ͽ� ��ü ����ġ���� ��� ��θ� �������� �ּҺ���� ����
// ( ��ü - �ּ� ����ġ)

int get_p(int a) {
	if (check[a] == a)return a;
	else return check[a] = get_p(check[a]);
}

int main()
{
	while (1) {
		int m, n;
		vector < pair<int, pair<int, int>>>vec;
		int answer=0;
		vector<int> tmp(200002,0);
		check = tmp;
		cin >> m >> n;
		if (m == 0 && n == 0)break;

		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vec.push_back({ c,{a,b} });
			answer += c;
		}

		for (int i = 0; i < m; i++)check[i] = i;

		sort(vec.begin(), vec.end());
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			int x = get_p(vec[i].second.first);
			int y = get_p(vec[i].second.second);
			int w = vec[i].first;
			//root�� ���� ������ �������ش�.
			if (x != y) {
				if (check[x] > y)check[x] = y;
				else check[y] = x;
				answer -= w;
			}
		}
		ans_vec.push_back(answer);
	}
	for (int i = 0; i < ans_vec.size(); i++)cout << ans_vec[i] << endl;

	return 0;
}
