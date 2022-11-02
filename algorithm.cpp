#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int N = 10010, M = 2 * N;
int n, ans;
bool vis[N];
int h[N], e[M], w[M], ne[M], idx;

void add(int a,int b,int c) {
    e[++idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}

int dfs(int u) {
    vis[u] = true;
    int d1 = 0;
    int d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int s = e[i];
        if (vis[s]) {
            continue;
        }
        int d = dfs(s) + w[i];
        if (d >= d2) {
            d2 = d;
        }
        if (d >= d1) {
            d2 = d1;
            d1 = d;
        }
        ans = max(ans, d1 + d2);
    }
    return d1;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1);
    cout << ans <<endl;
}