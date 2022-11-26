#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, m;
int w[105][105];
int d[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                w[i][j] = 0x7f7f7f7f;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
    }
    int ans = 0x7f7f7f7f;
    memcpy(d, w, sizeof d);
    for (int k = 1; k <= n; k++) {//在尚未开始第K轮循环时,假设最小环中编号最大的顶点为k
        for (int i = 1; i < k; i++) {//枚举相邻的两个点
            for (int j = i + 1; j < k; j++) {
                ans = min(ans, d[i][j] + w[j][k] + w[k][i]);
            }
        }
        for (int i = 1; i <= n; i++) {//floyd算法
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    if (ans == 0x7f7f7f7f) {
        cout << "No solution." <<endl;
    } else {
        cout << ans <<endl;
    }
}