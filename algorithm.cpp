#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 600000
#define M 600000
vector<int> e[N];
vector<pair<int,int>> query[N];
int fa[N], vis[N], ans[M];


int find(int u) {
    if (fa[u] == u) {
        return u;
    } else {
        return fa[u] = find(fa[u]);
    }
}

void tarjan(int u) {
    vis[u] = true;
    for (auto v: e[u]) {
        if (!vis[v]) {
            tarjan(v);
            fa[v] = u;
        }
    }
    for (auto q: query[u]) {
        int v = q.first;
        int i = q.second;
        if (vis[v]) {
            ans[i] = find(v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        query[a].push_back({b, i});
        query[b].push_back({a, i});
    }
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    tarjan(s);
    for (int i = 1; i <= m; i++) {
        cout << ans[i] <<endl;
    }
}