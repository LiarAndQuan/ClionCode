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

int n, m;
int times[100000];//记录每个点最短路径所含的边数


bool spfa(int s) {
    queue<int> q;
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (edge ed: e[u]) {
            int v = ed.v;
            int w = ed.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                times[v] = times[u] + 1;
                if (times[v] >= n) {//如果一个点的最短路径所含的边数大于等于n,那么一定有负环
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            e[i].clear();
            times[i] = 0;
            vis[i] = 0;
        }
        int s = 1;
        for (inti = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if (c >= 0) {
                e[b].push_back({a, c});
            }
            e[a].push_back({b, c});
        }
        if (spfa(1)) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" <<endl;
        }
    }
}