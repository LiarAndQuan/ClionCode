#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m, ans;
int dx[4] = {2, 1, -1, -2};
int dy[4] = {1, 2, 2, 1};


void dfs(int nowx, int nowy) {
    if (nowx == n && nowy == m) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = nowx + dx[i];
        int yy = nowy + dy[i];
        if (xx >= 0 && xx <= n && yy >= 0 && yy <= m ) {
            dfs(xx, yy);
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dfs(0, 0);
    cout <<ans<< endl;

}