#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 600000
#define M 600000

vector<int> e[N];
int fa[N], dep[N], son[N], sz[N];
int top[N];
int n, m, s;

void dfs1(int u,int father) {
    fa[u] = father;
    dep[u] = dep[father] + 1;
    sz[u] = 1;
    for (int v: e[u]) {
        if (v == father) {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) {
            son[u] = v;
        }
    }
}

void dfs2(int u,int t) {
    top[u] = t;
    if (!son[u]) {
        return;
    }
    dfs2(son[u], t);
    for (int v: e[u]) {
        if (v == fa[u] || v == son[u]) {
            continue;
        }
        dfs2(v, v);
    }
}

int lca(int u,int v) {
    while (top[u] != top[v]) {//不在一条链上
        if (dep[top[u]] < dep[top[v]]) {//保证始终是u往上跳
            swap(u, v);
        }
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;//在同一条重链上,深度较浅的返回
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(s, 0);
    dfs2(s, s);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) <<endl;
    }
}