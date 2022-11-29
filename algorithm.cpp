#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl'\n'
using namespace std;


#define N 100000

vector<int> e[N];
vector<int> ne[N];
int dfn[N], low[N], tot;
int scc[N], cnt;
stack<int> s;
int instack[N];
int w[N];
int wscc[N];
int dp[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    s.push(u);
    instack[u] = 1;
    for (int v: e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int v = -1;
        cnt++;
        while (v != u) {
            v = s.top();
            s.pop();
            instack[v] = 0;
            scc[v] = cnt;
            wscc[cnt] += w[v];
        }
    }
}

signed main() {


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {//建立拓扑图
        for (int j: e[i]) {
            int a = scc[i];
            int b = scc[j];
            if (a != b) {
                ne[a].push_back(b);
            }
        }
    }
    for (int i = cnt; i >= 0; i--) {//根据拓扑图序逆推
        if (dp[i] == 0) {
            dp[i] = wscc[i];
        }
        for (int j: ne[i]) {
            dp[j] = max(dp[j], dp[i] + wscc[j]);
        }
    }
    int ma = -1;
    for (int i = 1; i <= cnt; i++) {
        ma = max(ma, dp[i]);
    }
    cout << ma <<endl;
}