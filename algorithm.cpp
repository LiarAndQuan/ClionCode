#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w[100], f[100][3];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    f[0][1] = -1e6;
    f[0][0] = -1e6;
    f[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][1] = max(f[i - 1][1], f[i - 1][2] - w[i]);
        f[i][0] = f[i - 1][1] + w[i];
        f[i][2] = max(f[i - 1][0], f[i - 1][2]);
    }
    cout << max(f[n][0], f[n][2]);
}