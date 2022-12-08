#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define M 100000
#define N 100000
int n, m, k, ans;
struct edge {
    int v;
    int ne;
} e[M];

int h[N], idx;
int vis[N], match[N];


void add(int a, int b) {
    e[++idx] = {b, h[a]};
    h[a] = idx;
}

bool dfs(int u) {
    for (int i = h[u]; i; i = e[i].ne) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        vis[v] = 1;
        if (!match[v] || dfs(match[v])) {//如果这个点没有匹配或者匹配这个点的节点能够重新匹配新的点
            match[v] = u;//可以匹配
            return 1;//返回可以匹配的标志
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        if (dfs(i)) {
            ans++;
        }
    }
    cout << ans;
}