#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int N = 100010, INF = 0x3f3f3f3ff;
int n;
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx;
int d[N];
int f[N];
int deg[N];

void add(int a, int b, int c) {
    e[++idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}

int dfs_d(int u, int fa) {
    for (inti = h[u]; i; i = ne[i]) {
        int j = e[i];
        if (j == fa) {
            continue;
        }
        int s = dfs_d(j, u);
        d[u] += min(w[i], s);
    }
    if (deg[u] == 1) {
        return INF;
    } else {
        return d[u];
    }
}

void dfs_f(int u, int fa) {
    for (int i = h[u]; i; i = ne[i]) {
        int j = e[i];
        if (j == fa) {
            continue;
        }
        if (deg[u] == 1) {
            f[j] = d[j] + w[i];
        } else {
            f[j] = d[j] + min(w[i], f[u] - min(w[i], d[j]));
        }
        dfs_f(j, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        idx = 0;
        memset(h, 0, sizeof(h));
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        memset(deg, 0, sizeof(deg));
        for (inti = 1; i <= n - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            add(b, a, c);
            deg[a]++;
            deg[b]++;
        }
        dfs_d(1, -1);
        f[1] = d[1];//根只有向下的流量
        dfs_f(1, -1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}