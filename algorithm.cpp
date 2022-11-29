#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define N 100000

vector<int> e[N];
int dfn[N], low[N], tot;
int scc[N], cnt;
stack<int> s;
int instack[N];

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
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int out[N];
    for (int i = 1; i <= n; i++) {
        for (int j: e[i]) {
            if (scc[i] != scc[j]) {
                out[scc[i]]++;
            }
        }
    }
    int ans = 0;
    set<int> se;
    for (int i = 1; i <= n; i++) {
        if (out[scc[i]] == 0) {
            se.insert(scc[i]);
            ans++;
        }
    }
    if (se.size() > 1) {
        cout << 0 <<endl;
    } else {
        cout << ans <<endl;
    }
}