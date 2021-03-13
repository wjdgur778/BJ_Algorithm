//#include<iostream>
//#include<vector>
//#include<set>
//using namespace std;
//
//vector<int>check;
//vector<int>map[300001];
//set<int>s;
//int n, m;
//vector<bool>answer(300001, true);
//bool f = false;;
////����Ŭ�� ã�ƶ�
//// 
//void dfs(int except, int num,int pre) {
//	if (f)return;
////	cout << num << " ";
//	for (int i = 0; i < map[num].size(); i++) {
//		int next = map[num][i];
//		if (next == except)continue;
//		if (check[next] == false) {
//			check[next] = true;
//			dfs(except, next,num);
//			check[next] = false;
//		}
//		else {
//			if (pre != next) {
//				f = true;
//				answer[except] = false;
//			//	cout << " there is cycle! ";
//				return;
//			}
//		}
//	}
//
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int a = 0;
//		int b = 0;
//		cin >> a >> b;
//		map[a].push_back(b);
//		map[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++) {
//		vector<int>tmp(n+1);
//		check = tmp;
//		f = false;
//		if (i == n) {
//			check[1] = true;
//			dfs(i, 1, 1);
//		}
//		else {
//			check[i + 1] = true;
//			dfs(i, i + 1, i + 1); 
//		}
//		//cout << endl;
//	}
//	int sum = 0;
//	for (int i = 1; i <= n; i++)if (answer[i])sum += i;
//	cout<< sum;
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

#define MAXN 300005
#define pb push_back
typedef long long lld;

int N, M, C;
int dep[MAXN];
int U[MAXN], D[MAXN], F[MAXN];
/*
 * U[i] = i�� ��Ʈ�� ����Ʈ���� '������' ���Ե� back edge�� ��
 * D[i] = i�� ��Ʈ�� ����Ʈ���� '�����̶�' ���Ե� back edge�� ��
 * F[i] = i�� ��Ʈ�� ����Ʈ������ i�� �θ� �������� back edge�� ��
 */
vector <int> con[MAXN], child[MAXN];

void dfs(int n, int from)
{
    for (int t : con[n]) if (t != from) {
        if (!dep[t]) {
            // tree edge
            child[n].pb(t);
            dep[t] = dep[n] + 1;
            int tmp = U[n]; 

            dfs(t, n); 

            F[t] = U[n] - tmp;
            U[n] += U[t];
            D[n] += D[t];
        }
        else if (dep[t] < dep[n]) {
            // back edge
            D[n]++; U[t]++;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        con[a].pb(b); con[b].pb(a);
    }
    dep[1] = 1; dfs(1, 0);

    lld ans = 0;
    for (int i = 1; i <= N; i++) {
        bool skip = 0;
        for (int t : child[i])
            //i�� �θ𺸴� ���� �̾����� ������ 2�� �̻��� ��� ������ �����ϸ� tree edge�� back edge ��� ������
            //���� U[i]�� 1�� ��� i�� ��Ʈ�� ���� ����Ʈ�� �ȿ� ����Ŭ�� ����
            if (D[t] - F[t] > 1 || U[t]) skip = 1;
        //M - (N - 1) - D[i] �� 0 �� �ƴϸ� ��Ʈ i �� ������� back edge�� �����Ѵ�.
        if (skip || M - (N - 1) - D[i] != 0) continue;
        ans += i;
    }
    //cout << "U : ";
    //for (int i = 1; i <= N; i++)cout<<U[i] << " ";
    //cout << endl;
    //cout << "D : ";
    //for (int i = 1; i <= N; i++)cout << D[i] << " ";
    //cout << endl;
    //cout << "F : ";
    //for (int i = 1; i <= N; i++)cout <<F[i] << " ";
    //cout << endl;

    cout << ans;
}
