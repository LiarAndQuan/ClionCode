#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int v, w, c[100], f[100];

    for (int i = 0; i <= m; i++) {//不装物品也是一种方案
        c[i] = 1;
        f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            if (f[j - v] + w > f[j]) {//只是多装入一件物品,没有改变方案数
                f[j] = f[j - v] + w;
                c[j] = c[j - v];
            } else if (f[j - v] + w == f[j]) {
                c[j] = (c[j] + c[j - v]) % mod;
            }
        }
    }
    cout << c[m];
}