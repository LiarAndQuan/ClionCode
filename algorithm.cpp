#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n;
int a[200], f[200][200];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int len = 3; len <= n + 1; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = len + l - 1;
            for (int k = l + 1; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i][i + n]);
    }
    cout << res <<endl;
}