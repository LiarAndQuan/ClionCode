#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int N = 1e5 + 10;
int n, ans = N;
bool vis[N];
int h[N], e[2 * N], ne[2 * N], idx;

void add(int a, int b) {
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int dfs(int u) {
    vis[u] = true;
    int size = 0;//最大子树的节点数
    int sum = 1;//以u为根的子树的节点数
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (vis[j]) {
            continue;
        }
        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    ans = min(ans, max(size, n - sum));
    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
}