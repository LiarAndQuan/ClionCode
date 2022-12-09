#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define INF 0x3f3f3f3f
#define N 1000
int match[N];
int va[N], vb[N];
int la[N], lb[N];
int w[N][N], d[N];

int n;

bool dfs(int x) {
    va[x] = 1;//标记x在交替路中
    for (int y = 1; y <= n; y++) {
        if (!vb[y]) {
            if (la[x] + lb[y] - w[x][y] == 0) {//如果是相等子图
                vb[y] = 1;//y在交替路中
                if (!match[y] || dfs(match[y])) {
                    match[y] = x;//配对
                    return 1;
                }
            } else {//不是相等子图就记录下最小的d[y]
                d[y] = min(d[y], la[x] + lb[y] - w[x][y]);
            }
        }
    }
    return 0;
}

int KM() {
    for (int i = 1; i <= n; i++) {
        la[i] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            la[i] = max(la[i], w[i][j]);//左顶点值为最大边权
        }
    }
    for (int i = 1; i <= n; i++) {
        lb[i] = 0;//右顶点值为0
    }
    for (int i = 1; i <= n; i++) {
        while (true) {
            memset(va, 0, sizeof va);//每个点进去时状态重置
            memset(vb, 0, sizeof vb);
            for (int j = 1; j <= n; j++) {
                d[j] = INF;
            }
            if (dfs(i)) {//如果成功配对,配对下一个
                break;
            }
            int delta = INF;
            for (int j = 1; j <= n; j++) {
                if (!vb[j]) {
                    delta = min(delta, d[j]);//如果没有成功配对,取出最小的delta
                }
            }
            for (int j = 1; j <= n; j++) {
                if (va[j]) {
                    la[j] -= delta;//对每一个在交替路中的顶点值进行修改
                }
                if (vb[j]) {
                    lb[j] += delta;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {//累加结果
        res += w[match[i]][i];
    }
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = -INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = c;
    }
    cout << KM() << endl;
}