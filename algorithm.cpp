#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, V, M;
    cin >> n >> V >> M;
    int v, w, m, f[100][100];
    for (int i = 1; i <= n; i++) {
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--) {
            for (int k = M; k >= m; k--) {
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
            }
        }
    }
    cout << f[V][M];
}