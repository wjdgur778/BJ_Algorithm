#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

vector<int>vec_1;
vector<pair<int, int>>vec_2;
int N;
/*N���� �� �߿��� � ���� �ٸ� �� �� ���� ������ ��Ÿ�� �� �ִٸ� �� ���� ������(GOOD)���� �Ѵ�.
N���� ���� �־����� �� �߿��� ���� ���� ������ �� ������ ����϶�.
���� ��ġ�� �ٸ��� ���� ���Ƶ� �ٸ� ���̴�.*/


//������ 2���� ���� �ƴ� �ٸ��� 2���� ��!!!!!!!
//lower ��  upper ���̿� �ִ� �ߺ������� ���� ���ϴ� ���� ã�°��� ���� ���� ����ϱ�...?
//�ȿ����� ���ϳ�..
// 1. �ߺ�ó���� ��� �Ұ�����
// 2. ���� lower �� upper �� ��� ����Ұǵ�?
// 3. lower����� �ٸ������� ���ö����� �ݺ��� �ص� �ɰŰ���. ex) 2���� binary_search�� �ƴ� 1���� binary_search�� �� �� target�� �޶��������� �ε����� ���ư���.
//


//�ʹ� ��ư� Ǭ ���� �����ʴ�...
//��� �׳� ���ʿ��� ���� ���� ������ ����;;

bool comp(pair<int, int>a, pair<int, int>b) {
	return vec_1[a.first]+vec_1[a.second] < vec_1[b.first]+vec_1[b.second];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec_1.push_back(a);
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			vec_2.push_back({ i,j }
			);
		}
	}
	sort(vec_2.begin(), vec_2.end(), comp);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int s = 0;
		int e = vec_2.size() - 1;
		bool check = false;
		int target = vec_1[i];
		while (s <= e) {
			int mid = (s + e) / 2;
			int sum = vec_1[vec_2[mid].first] + vec_1[vec_2[mid].second];
			if (target >= sum) {
				s = mid + 1;
				if (target == sum && vec_2[mid].first != i && vec_2[mid].second != i)
					check = true;
			}
			else {
				e = mid - 1;
			}
		}
		s = 0;
		e = vec_2.size() - 1;
		while (s <= e) {
			int mid = (s + e) / 2;
			int sum = vec_1[vec_2[mid].first] + vec_1[vec_2[mid].second];
			if (target > sum) {
				s = mid + 1;
			}
			else {
				if (target == sum && vec_2[mid].first != i && vec_2[mid].second != i)
					check = true;
				e = mid - 1;
			}
		}
		if (check) {
			answer++;
		}
	}
	cout << answer;

	return 0;
}