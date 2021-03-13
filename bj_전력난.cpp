#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> check;
vector<int>ans_vec;


/*
성진이는 한 도시의 시장인데 거지라서 전력난에 끙끙댄다. 그래서 모든 길마다 원래 켜져 있던 가로등 중 일부를 소등하기로 하였다. 길의 가로등을 켜 두면 하루에 길의 미터 수만큼 돈이 들어가는데, 일부를 소등하여 그만큼의 돈을 절약할 수 있다.

그러나 만약 어떤 두 집을 왕래할 때, 불이 켜져 있지 않은 길을 반드시 지나야 한다면 위험하다. 그래서 도시에 있는 모든 두 집 쌍에 대해, 불이 켜진 길만으로 서로를 왕래할 수 있어야 한다.

위 조건을 지키면서 절약할 수 있는 최대 액수를 구하시오.
*/

//text case에 대한 말을 애매하게 예제로 두고 하라는건 무슨 심보인데;;
//최소 스패닝트리
//쇠소 스패닝 트리를 이용하여 전체 가중치에서 모든 경로를 잇을때의 최소비용을 뺀다
// ( 전체 - 최소 가중치)

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
			//root가 같지 않으면 연결해준다.
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
