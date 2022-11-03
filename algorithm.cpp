#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int w[100], f[100][100][2];
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    memset(f, 0, sizeof(f));

    for (int j = 0; j <= k; j++) {
        f[0][j][1] = -1e6;//前0天举行了k次交易手中有票不合法.
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
        }
    }
    cout << f[n][k][0];
}