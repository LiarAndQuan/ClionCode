#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int f[100], v[200], w[200];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (inti = 1; i <= n; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> v[j] >> w[j];
        }

        for (int j = m; j >= 0; j--) {
            for (int k = 0; k <= s; k++) {
                if (j >= v[k]) {
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
                }
            }
        }
    }
    cout << f[m] <<endl;
}