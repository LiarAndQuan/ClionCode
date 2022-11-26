#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define N 1000000

struct edge {
    int u, v, w;
    bool operator<(const edge &t) const {
        return w < t.w;
    }
} e[N];

int n, m;
int fa[N], ans, cnt;

int find(int x) {
    if (fa[x] == x) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}

bool Kruskal() {
    sort(e + 1, e + 1 + 2 * m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= 2 * m; i++) {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (x != y) {//如果x,y不在同一个集合里面
            fa[x] = y;
            ans += e[i].w;
            cnt++;
        }
    }
    return cnt == n - 1;//需要结合n-1次才能保证连通
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
        e[i + m] = {b, a, c};
    }
    if (Kruskal()) {
        cout << ans;
    } else {
        cout << "orz" <<endl;
    }
}