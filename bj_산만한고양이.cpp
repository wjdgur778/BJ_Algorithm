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
////사이클을 찾아라
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
 * U[i] = i가 루트인 서브트리에 '완전히' 포함된 back edge의 수
 * D[i] = i가 루트인 서브트리에 '조금이라도' 포함된 back edge의 수
 * F[i] = i가 루트인 서브트리에서 i의 부모가 목적지인 back edge의 수
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
            //i의 부모보다 위로 이어지는 간선이 2개 이상인 경우 정점을 제거하면 tree edge와 back edge 모두 생성됨
            //또한 U[i]이 1인 경우 i를 루트로 갖는 서브트리 안에 사이클이 존재
            if (D[t] - F[t] > 1 || U[t]) skip = 1;
        //M - (N - 1) - D[i] 이 0 이 아니면 루트 i 와 상관없이 back edge가 존재한다.
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
