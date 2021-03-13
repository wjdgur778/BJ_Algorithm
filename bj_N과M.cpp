#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int N;
int M;
vector<int>vec;
vector<vector<int>> answer;
set<int> just_c;
vector<int> s;

/*N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.*/


//�Ϲ� ������ �����ִ�.
//������ ��θ� ���Ϳ� �ְ� ����Ʈ�� �Ѵٸ� ��û�� ���ϰ� �ɸ�
// M���� �̾����� ���� ����� �ϴ� ������ �غ���

void dfs(int cnt) {
	if (cnt == M) {//�ߺ� �Ǹ�
		for (int i = 0; i < s.size(); i++)cout << s[i] << " ";
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		s.push_back(vec[i]);
		dfs(cnt + 1);
		s.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (just_c.find(a) == just_c.end()) {
			just_c.insert(a);
			vec.push_back(a);
		}
	}
	sort(vec.begin(), vec.end());
	dfs(0);

	return 0;
}