#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, m;
char arr[105][105];
int ans;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int xx = p.first + dx[k];
            int yy = p.second + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arr[xx][yy] == 'W') {
                arr[xx][yy] = '.';
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
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 'W') {
                ans++;
                arr[i][j] = '.';
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;

}