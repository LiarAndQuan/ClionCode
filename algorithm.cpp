#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 50000

struct edge {
    int v;
    int c;
    int w;
    int ne;
} e[2000000];

int h[N], idx = 1;
int d[N], mf[N], pre[N], vis[N];
int flow, cost;
int s, t;

void add(int a, int b, int c, int x) {
    e[++idx] = {b, c, x, h[a]};
    h[a] = idx;
}

bool spfa() {
    memset(d, 0x3f, sizeof d);
    memset(mf, 0, sizeof mf);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    mf[s] = 0x3f3f3f3f;
    vis[s] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = h[u]; i; i = e[i].ne) {
            int v = e[i].v;
            int c = e[i].c;
            int w = e[i].w;
            if (d[v] > d[u] + w && c) {
                d[v] = d[u] + w;
                mf[v] = min(mf[u], c);
                pre[v] = i;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return mf[t] > 0;//可行流能到达t点
}

void EK() {
    while (spfa()) {
        for (int v = t; v != s;) {
            int i = pre[v];
            e[i].c -= mf[t];
            e[i ^ 1].c += mf[t];
            v = e[i ^ 1].v;
        }
        flow += mf[t];
        cost += mf[t] * d[t];//累加费用
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int a, b, c, x;
        cin >> a >> b >> c >> x;
        add(a, b, c, x);
        add(b, a, 0, -x);
    }
    EK();
    cout << flow << " " << cost;
}