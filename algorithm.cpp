#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int f[200], g[200], q[200];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int v, w, s;

    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        memcpy(g, f, sizeof(f));
        //准备一个备份数组,因为多重背包需要我们从后往前更新,但是单调队列需要我们从前往后更新
        for (int j = 0; j < v; j++) {
            int h = 0, t = -1;
            for (int k = j; k <= m; k += v) {
                if (h <= t && k - q[h] > s * v) {
                    h++;
                }
                if (h <= t) {
                    f[k] = max(g[k], g[q[h]] + (k - q[h]) / v * w);
                }
                while (h <= t && g[k] >= g[q[t]] + (k - q[t]) / v * w) {
                    t--;
                }
                q[++t] = k;
            }
        }
    }
    cout << f[m];
}