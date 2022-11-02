#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;
int n;
int h[N], e[2 * N], w[2 * N], ne[2 * N], idx;
int d1[N], d2[N], p1[N], up[N];

int dfs_d(int u,int father) {
    d1[u] = 0;
    d2[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) {
            continue;
        }
        int d = dfs_d(j, u) + w[i];
        if (d >= d1[u]) {
            d2[u] = d1[u];
            d1[u] = d;
            p1[u] = j;
        } else if (d > d2[u]) {
            d2[u] = d;
        }
    }
    return d1[u];
}

void dfs_u(int u,int father) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) {
            continue;
        }
        if (p1[u] == j) {
            up[j] = max(up[u], d2[u]) + w[i];
        } else {
            up[j] = max(up[u], d1[u]) + w[i];
        }
        dfs_u(j, u);
    }
}

void add(int a,int b,int c) {
    e[++idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs_d(1, -1);
    dfs_u(1, -1);
    int res = INF;
    for (int i = 1; i <= n; i++) {
        res = min(res, max(up[i], d1[i]));
    }
    cout<<res;
}