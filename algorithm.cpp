#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define N 100005
#define M 100006

struct edge {
    int v;
    int c;
    int ne;

    bool operator<(const edge &e) const {
        return c > e.c;
    }
} e[N];

int d[N];

int s, t;
int h[N], idx = 1;
int cur[N];


bool bfs() {
    memset(d, 0, sizeof d);
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {
            int v = e[i].v;
            if (!d[v] && e[i].c) {
                d[v] = d[u] + 1;
                q.push(v);
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

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
            mf -= f;
            sum += f;
        }
        if (mf == 0) {
            break;
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
    int u[1005];
    int v[1005];
    int w[1005];
    int n, m;
    cin >> n >> m;
    s = 1;
    t = n;

    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        add(u[i], v[i], w[i] * 2018 + 1);
        add(v[i], u[i], 0);
    }
    int a = dinic();
    cout << a / 2018 << " " << a % 2018;
}