#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, m, ans, cnt;
struct edge {
    int v;
    int w;
};

vector<edge> e[10000];
int d[10000];
int vis[10000];
priority_queue<pair<int,int> > q;

bool prim(int s) {
    for (int i = 0; i <= n; i++) {
        d[i] = 0x3f3f3f3f;
    }
    d[s] = 0;
    q.push({0, s});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        ans += d[u];
        cnt++;
        for (auto ed: e[u]) {//对于u点的所有的边的点,更新他们的距离
            int v = ed.v;
            int w = ed.w;
            if (d[v] > w) {
                d[v] = w;
                q.push({-d[v], v});
            }
        }
    }
    return cnt == n;//如果能够组成最小生成树返回true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});

    }
    if (prim(1)) {
        cout << ans <<endl;
    } else {
        cout << "orz" <<endl;
    }
}