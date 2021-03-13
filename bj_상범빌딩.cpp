#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


//단순 bfs이지만 3차원과 초기화~~~~~~


int main() {
    while (true) {
        int map[31][31][31];
        bool check[31][31][31];
        queue< pair<int, pair<int, int>>>q;
        int L, R, C;
        int dx[6] = { 0,1,0,-1,0,0 };
        int dy[6] = { 1,0,-1,0,0,0 };
        int dz[6] = { 0,0,0,0,1,-1 };
        pair<int, pair<int, int>>s;
        pair<int, pair<int, int>>e;

        //init
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)break;


        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    check[i][j][k] = false;
                    char a;
                    cin >> a;
                    map[i][j][k] = a;
                    if (a == 'S') {
                        s.first = i;
                        s.second.first = j;
                        s.second.second = k;
                    }
                }
            }
        }
        //logic
        q.push(s);
        check[s.first][s.second.first][s.second.second] = true;
        int cnt=0;
        bool f = true;

        while (!q.empty()&&f) {
            int size = q.size();
            cnt++;
            for (int j = 0; j < size; j++) {
                pair<int, pair<int, int>>cur = q.front();

                for (int i = 0; i < 6; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second.first + dy[i];
                    int nz = cur.second.second + dz[i];
                    if (nx > L - 1 || ny > R - 1 || nz > C-1 || nx < 0 || ny < 0 || nz < 0)continue;
                    if (map[nx][ny][nz] == '#')continue;
                    if (check[nx][ny][nz] == true)continue;

                    if (f && map[nx][ny][nz] == 'E') {
                        cout << "Escaped in " << cnt << " minute(s)." << '\n';
                        f = false;
                        break;
                    }
                    q.push({ nx,{ny,nz} });
                    check[nx][ny][nz] = true;
                }
                q.pop();
            }
        }
        if (f)cout << "Trapped!" << '\n';

    }

    return 0;
}