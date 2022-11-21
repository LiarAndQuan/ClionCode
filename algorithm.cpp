#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m;
int a, b, x, y;
int arr[200][200];
int res;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[200][200];


void dfs(int nowx, int nowy) {

    if (nowx == x && nowy == y) {
        res++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int xx = nowx + dx[i];
        int yy = nowy + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == 0 && arr[xx][yy] == 0) {
            vis[xx][yy] = 1;
            dfs(xx, yy);
            vis[xx][yy] = 0;
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> n >> m >> t;
    cin >> a >> b >> x >> y;
    for (int i = 1; i <= t; i++) {
        int w, v;
        cin >> w >> v;
        arr[w][v] = 1;
    }
    vis[a][b] = 1;
    dfs(a, b);
    cout << res << endl;
}