#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


struct edge {
    int v;
    int w;
};

vector<edge> e[100005];
int d[100005], vis[100005];
priority_queue<pair<int,int>> q;
int n, m;


void dijkstra(int s) {
    for (int i = 0; i <= n; i++) {
        d[i] = pow(2, 31) - 1;
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
    int s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}