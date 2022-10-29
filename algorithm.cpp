#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int v[100], w[100], root, a[100][100], b[100], f[100][100];
int n, m;

void dfs(int u) {
    for (int i = v[u]; i <= m; i++) {
        f[u][i] = w[u];
    }
    for (int i = 0; i < b[u]; i++) {
        int s = a[u][i];
        dfs(s);
        for (int j = m; j >= v[u]; j--) {//子父节点一共能用的容量
            for (int k = 0; k <= j - v[u]; k++) {//将容量分配到子节点
                f[u][j] = max(f[u][j], f[u][j - k] + f[s][k]);
            }
        }
    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1) {
            root = i;
        } else {
            a[p][b[p]++] = i;
        }
    }
    dfs(root);
    cout << f[root][m];
}
