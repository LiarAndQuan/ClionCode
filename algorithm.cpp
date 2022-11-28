#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 600000
#define lc u<<1
#define rc (u<<1)+1

int w[N];
vector<int> e[N];
int fa[N], dep[N], sz[N], son[N];
int top[N], id[N], nw[N], cnt;

struct tree {
    int l, r;
    int add, sum;
} tr[4 *N];

void pushup(int u) {
    tr[u].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int u) {
    if (tr[u].add) {
        tr[lc].sum += tr[u].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[u].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[u].add;
        tr[rc].add += tr[u].add;
        tr[u].add = 0;
    }
}

void build(int u,int l,int r) {
    tr[u] = {l, r, 0, nw[r]};
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(u);
}

int query(int u,int l,int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) {
        res += query(lc, l, r);
    }
    if (r > mid) {
        res += query(rc, l, r);
    }
    return res;
}

int query_path(int u,int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            swap(u, v);
        }
        res += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    res += query(1, id[v], id[u]);
    return res;
}

void update(int u,int l,int r,int k) {
    if (l <= tr[u].l && r >= tr[u].r) {
        tr[u].add += k;
        tr[u].sum += k * (tr[u].r - tr[u].l + 1);
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        update(lc, l, r, k);
    }
    if (r > mid) {
        update(rc, l, r, k);
    }
    pushup(u);
}

void update_path(int u,int v,int k) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            swap(u, v);
        }
        update(1, id[top[u]], id[u], k);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    update(1, id[v], id[u], k);
}

void dfs1(int u,int father) {
    fa[u] = father;
    dep[u] = dep[father] + 1;
    sz[u] = 1;
    for (int v: e[u]) {
        if (v == father) {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) {
            son[u] = v;
        }
    }
}

void dfs2(int u,int t) {
    top[u] = t;
    id[u] = ++cnt;
    nw[cnt] = w[u];
    if (!son[u]) {
        return;
    }
    dfs2(son[u], t);
    for (int v: e[u]) {
        if (v == fa[u] || v == son[u]) {
            continue;
        }
        dfs2(v, v);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r, p;
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs1(r, 0);
    dfs2(r, r);

    build(1, 1, n);

    for (inti = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            update_path(a, b, c);
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b) % p <<endl;
        } else if (op == 3) {
            int a, b;
            cin >> a >> b;
            update(1, id[a], id[a] + sz[a] - 1, b);
        } else {
            int a;
            cin >> a;
            cout << query(1, id[a], id[a] + sz[a] - 1) % p <<endl;
        }
    }
}