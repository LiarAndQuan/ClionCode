#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int vv[100], ww[100], f[100];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 1;
    int n, m;
    cin >> n >> m;
    int v, w, s;

    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int j = 1; j <= s; j <<= 1) {
            vv[num] = j * v;
            ww[num++] = j * w;
            s -= j;
        }
        if (s) {
            vv[num] = s * v;
            ww[num++] = s * w;
        }
    }

    for (int i = 1; i < num; i++) {
        for (int j = m; j >= vv[i]; j--) {
            f[j] = max(f[j], f[j - vv[i]] + ww[i]);
        }
    }
    cout << f[m];
}
