#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 10000

struct edge {
    int u;
    int v;
};

vector<edge> e;
vector<int> h[N];
int dfn[N], low[N], tot, cnt;

struct bridge {
    int x;
    int y;
    bool operator<(const bridge &b) const {
        if (x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }
} bridge[2 *N];

void add(int a,int b) {
    e.push_back({a, b});
    h[a].push_back(e.size() - 1);
}

void tarjan(int x,int in_edge) {
    dfn[x] = low[x] = ++tot;
    for (int i = 0; i < h[x].size(); i++) {
        int j = h[x][i];
        int y = e[j].v;
        if (!dfn[y]) {//如果y没有访问过
            tarjan(y, j);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {//满足割边条件
                bridge[++cnt] = {x, y};
            }
        } else if (j != (in_edge ^ 1)) {//如果访问过并且不是走的反边
            low[x] = min(low[x], dfn[y]);
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
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -2);
        }
    }
    sort(bridge + 1, bridge + 1 + cnt);
    for (inti = 1; i <= cnt; i++) {
        cout << bridge[i].x << " " << bridge[i].y <<endl;
    }
}