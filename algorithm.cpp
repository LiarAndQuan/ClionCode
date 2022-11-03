#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int w[100];
    int f[100][2];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    f[1][0] = 0;
    f[1][1] = -w[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + w[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - w[i]);
    }
    cout << f[n][0];
}