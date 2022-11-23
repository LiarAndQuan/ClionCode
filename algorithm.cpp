#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int g[100][100];
int dis[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;


void bfs() {
    memset(dis, -1, sizeof(dis));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 1) {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }

    while (q.size()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = cur.first + dx[i];
            int yy = cur.second + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dis[xx][yy] == -1) {
                dis[xx][yy] = dis[cur.first][cur.second] + 1;
                q.push({xx, yy});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}