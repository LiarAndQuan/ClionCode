#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int N = 5e5 + 10;
int n, m, s;
vector<int> e[N];
int dep[N], fa[N][35];
int head[N];


void dfs(int u,int father) {
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i <= 31; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int v: e[u]) {
        if (v != father) {
            dfs(v, u);
        }
    }

}

int lca(int u,int v) {
    if (dep[u] < dep[v]) {//确保u为深度更大的点
        swap(u, v);
    }
    for (int i = 31; i >= 0; i--) {//先跳到同一层
        if (dep[fa[u][i]] >= dep[v]) {//如果u跳完,v还在u的上面,那就可以跳
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 31; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {//跳完之后不相等的话,那就可以跳
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) <<endl;
    }
}