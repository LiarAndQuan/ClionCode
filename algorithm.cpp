#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m;
int g[14];
int cnt;
int s[1 << 14];
int f[14][1 << 14];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {//将土地的二进制转换为十进制
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            g[i] = (g[i] << 1) + x;
        }
    }
    for (int i = 0; i < (1 << m); i++) {//保存同行中可行的状态
        if (!(i & i >> 1)) {
            s[cnt++] = i;
        }
    }
    f[0][0] = 1;//什么都不中是一种方案

    for (int i = 1; i <= n + 1; i++) {
        for (int a = 0; a < cnt; a++) {
            for (int b = 0; b < cnt; b++) {
                //a b同列不同时为1&&a种在肥沃土地上
                if (!(s[a] & s[b]) && (s[a] & g[i]) == s[a]) {
                    f[i][a] += f[i - 1][b];
                }
            }
        }
    }
    cout << f[n + 1][0];
}