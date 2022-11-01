#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n;
int w[100], fa[100], f[100][100];
int a[100][100], b[100];

void dfs(int u) {
    f[u][1] = w[u];//选u
    for (int i = 0; i < b[u]; i++) {
        int son = a[u][i];
        dfs(son);
        f[u][0] += max(f[son][0], f[son][1]);
        f[u][1] += f[son][0];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        a[y][b[y]++] = x;
        fa[x] = true;//x有父节点
    }
    int root = 1;
    while (fa[root]) root++;//找到根节点
    dfs(root);
    cout << max(f[root][0], f[root][1]);
}
