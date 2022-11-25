#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl'\n'
using namespace std;

struct edge {
    int v, w;
};

vector<edge> e[3005];
int vis[3005];
int n, m;
int d[3005], times[3005], h[3005];

bool spfa(int s) {
    queue<int> q;
    memset(vis, 0, sizeof vis);
    for (inti = 0; i <= n; i++) {
        h[i] = 1e9;
    }
    h[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (edge ed: e[u]) {
            int v = ed.v;
            int w = ed.w;
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                times[v] = times[u] + 1;
                if (times[v] > n) {//建立虚拟源点之后一共有n+1个点
                    return true;
                }
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

void dijkstra(ints) {
    priority_queue<pair<int,int>> q;
    memset(vis, 0, sizeof vis);
    for (inti = 0; i <= n; i++) {
        d[i] = 1e9;
    }
    d[s] = 0;
    q.push({0, s});
    while (q.size()) {
        auto t = q.top();
        q.pop();
        if (vis[t.second]) {
            continue;
        }
        vis[t.second] = 1;
        for (auto ed: e[t.second]) {
            int v = ed.v;
            int w = ed.w;
            if (d[v] > d[t.second] + w) {
                d[v] = d[t.second] + w;
                q.push({-d[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (inti = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        e[0].push_back({i, 0});
    }

    if (spfa(0)) {
        cout << "-1 " <<endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (auto &ed: e[i]) {
            ed.w += h[i] - h[ed.v];
        }
    }

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (d[j] == pow(10, 9)) {
                ans += j * pow(10, 9);
            } else {
                ans += j * (d[j] + h[j] - h[i]);
            }
        }
        cout << ans <<endl;
    }
}