#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int v[200], w[200], f[200];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[m] << endl;
}