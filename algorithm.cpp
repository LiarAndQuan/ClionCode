#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 100000

int d[N];
int s, t;
int vis[N];
struct edge {
    int v;
    int c;
    int ne;
} e[2 * N];
int h[N], idx = 1;

bool bfs() {
    memset(d, 0, sizeof d);
    memset(vis, 0, sizeof vis);
    d[s] = 1;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int i = h[cur]; i; i = e[i].ne) {
            int v = e[i].v;
            if (!vis[v] && e[i].c) {
                vis[v] = 1;
                q.push(v);
                d[v] = d[cur] + 1;
                if (v == t) {//放在里面才行
                    return true;
                }
            }
        }
    }
    return false;
}

int cur[N];

int dfs(int u, int mf) {
    if (u == t) {
        return mf;
    }
    int sum = 0;
    for (int i = cur[u]; i; i = e[i].ne) {
        cur[u] = i;
        int v = e[i].v;
        if (d[v] == d[u] + 1 && e[i].c) {
            int f = dfs(v, min(mf, e[i].c));
            e[i].c -= f;
            e[i ^ 1].c += f;
            sum += f;
            mf -= f;
            if (mf == 0) {
                break;
            }
        }
    }
    if (sum == 0) {
        d[u] = 0;
    }
    return sum;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memcpy(cur, h, sizeof h);
        flow += dfs(s, 1e9);
    }
    return flow;
}

void add(int a, int b, int c) {
    e[++idx] = {b, c, h[a]};
    h[a] = idx;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= x; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b + n, 1);//每条正向边的边权都为1
        add(b + n, a, 0);//反向边的边权为0
    }
    s = 0;
    t = n + m + 1;
    for (int i = 1; i <= n; i++) {
        add(s, i, 1);//超级源点到左边点的距离为1
        add(i, s, 0);
    }
    for (int i = 1; i <= m; i++) {
        add(i + n, t, 1);//右边点到超级汇点的距离为1
        add(t, i + n, 0);
    }
    cout << dinic();
}