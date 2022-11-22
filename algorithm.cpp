#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, m;
int arr[200][200];
int a, b, x, y;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> ps[200][200];


void print(int i, int j) {
    if (i == a && j == b) {
        return;
    } else {
        print(ps[i][j].first, ps[i][j].second);
        cout << ps[i][j].first << " " << ps[i][j].second << endl;
    }
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == x && cur.second == y) {
            print(x, y);
            cout << x << " " << y << endl;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int xx = cur.first + dx[k];
            int yy = cur.second + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arr[xx][yy] == 0) {
                arr[xx][yy] = 1;
                q.push({xx, yy});
                ps[xx][yy] = cur;
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> a >> b >> x >> y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    bfs(a, b);
}

