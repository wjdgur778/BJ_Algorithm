//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//int H;
//vector<int>vec_1;
//vector<int>vec_2;
//
////binary search
//// �ִ������� ��ġ�°��� ���ؾ� �Ѵ�
//// ó���� ���ľ� �Ѵ�? ��� �����ߴ�.
//// �׷��ٸ� �� �ݴ�θ� �ϸ� �ɱ�?
//
//

/*
- ���� �߿��ߴ����� ������ ������ ���� target�� ã���� �� ���Ĵ� ��� ��ֹ��� ���������Ѵٴ� ����(�Ӹ������� �� ����)�ؾ� �Ѵٴ°�!!
- ���� ��� 1 2 4 5 5 6 7 8 10 ���� ���ĵǾ��ִ� ������ 2�� ����Ѵٰ� �ϸ� �迭 �ӿ��� key = 2 �� ã�Ƴ��� �� ���ķ� ū ������ ��� (�翬�ϰ�) �������ٴ� ���̴�.

*/

//int main(){
//	cin >> N >> H;
//	for (int i = 0; i < N; i++) {
//		int a;
//		cin >> a;
//		if (i % 2 == 0)vec_1.push_back(a);
//		else vec_2.push_back(a);
//	}
//	sort(vec_1.begin(), vec_1.end());
//	sort(vec_2.begin(), vec_2.end(),greater<int>());
//	int s = 1;
//	int e = H;
//	int cnt = 0;
//	
//	int answer = 200001;
//	//��ġ�±����� �߰��� ã�ƺ���
//	while (s <= e) {
//		int mid = (s + e) / 2;
//		int sum_1 = 0;
//		int sum_2 = 0;
//		for (int i = 0; i < vec_1.size(); i++) {
//			if (mid <= vec_1[i])sum_1++;
//		}
//		for (int i = 0; i < vec_2.size(); i++) {
//			if (mid > H - vec_2[i])sum_2++;
//		}
//		if (answer > sum_1+sum_2) {
//			answer = sum_1 + sum_2;
//			s = mid + 1;
//		}
//		else {
//			e = mid - 1;
//		}
//	}
////	cout << cnt << endl;;
//	int s_1 = 1;
//	int e_1 = H;
//	int cnt_1 = 0;
//	int min_1 = 987654321;
//	while (s_1 <= e_1) {
//		int mid = (s_1 + e_1) / 2;
//		int sum_1 = 0;
//		int sum_2 = 0;
//		for (int i = 0; i < vec_1.size(); i++) {
//			if (mid <= vec_1[i])sum_1++;
//		}
//		for (int i = 0; i < vec_2.size(); i++) {
//			if (mid > H - vec_2[i])sum_2++;
//		}
//		if (sum_1 > sum_2) {
//			e_1 = mid - 1;
//		}
//		else {
//			s_1 = mid + 1;
//			if (answer == sum_1 + sum_2)cnt_1++;
//			else cnt_1 = 1;
//			answer = min(answer, sum_1 + sum_2);
//			//cout << "answer  " << answer << endl;
//		}
//	}
//	cout << answer << " " << cnt+cnt_1-1;
//	return 0;
//}


//�������� �������� ó������ �ٽ� �ϴ���...
//�� 
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//int H;
//vector<int>up;
//vector<int>down;
//int sum_u[500001];
//int sum_d[500001];
//int main() {
//	cin >> N >> H;
//	for (int i = 0; i < N; i++) {
//		int a;
//		cin >> a;
//		if (i % 2 == 0) {
//			sum_d[a]++;
//		}
//		else sum_u[H-a+1]++;
//	}
//
//	for (int i = H; i >= 1; i--) {
//		sum_d[i-1] += sum_d[i];
//	}
//	for (int i = 2; i <= H; i++) {
//		sum_u[i] += sum_u[i-1];
//	}
//	int s = 1;
//	int e = H;
//	int answer = 200001;
//	int cnt = 0;
//	for (int i = 1; i <= H; i++) {
//		if (answer > sum_u[i] + sum_d[i]) {
//			answer = sum_u[i] + sum_d[i];
//			cnt = 1;
//		}
//		else if (answer == sum_u[i] + sum_d[i]) {
//			cnt++;
//		}
//	}
//	cout << answer << " "<<cnt;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int INF = 987654321;

int main(void)
{

    int N, H;
    cin >> N >> H;
    vector<int> bottom(N / 2), top(N / 2);

    for (int i = 0; i < N / 2; i++) {
        int t = 0;
    
        cin >> bottom[i]>>t;
        top[i] = H - t + 1;
    }



    sort(bottom.begin(), bottom.end());

    sort(top.begin(), top.end());
    int result = INF;
    int cnt = 1;

    for (int i = 1; i <= H; i++)

    {

        //�ش� ���̿� ��ġ�� ����
        //lower�� ����ϴ� ������ ���� ���� ���ö� �װ͵��� 
        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
        //�ش� ���̿� ��ġ�� ������
        temp +=(upper_bound(top.begin(), top.end(), i) - top.begin());



        if (result == temp)
            cnt++;
        else if (result > temp)
        {

            result = temp;

            cnt = 1;

        }

    }

    cout << result << " " << cnt << "\n";

    return 0;

}
