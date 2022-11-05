#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m;//行数,列数
int g[10];//保存地图各行数值
int cnt;//同一行的合法状态数量
int s[1 << 10];//同一行的合法状态集合
int num[1 << 10];//每个合法状态包含的1的个数
int f[10][1 << 10][1 << 10];
//前i行,第i行是第j个状态,第i-1行是第k个状态时,能放置点最大数量

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {//地图转成二进制
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'P') {
                g[i] += 1 << (m - j - 1);
            }
        }
    }
    for (int i = 0; i < (1 << m); i++) {//枚举合法状态
        if (!(i & i >> 1) && !(i & i >> 2)) {
            s[cnt++] = i;
            for (int j = 0; j < m; j++) {
                num[i] += (i >> j & 1);
            }
        }
    }
    for (int i = 1; i <= n + 2; i++) {
        for (int a = 0; a < cnt; a++) {//枚举第i行
            for (int b = 0; b < cnt; b++) {//枚举第i-1行
                for (int c = 0; c < cnt; c++) {//枚举第i-2行
                    if (!(s[a] & s[b]) && !(s[b] & s[c]) && !(s[a] & s[c]) && (g[i] & s[a]) == s[a] &&
                        (g[i - 1] & s[b]) == s[b]) {
                        f[i][a][b] = max(f[i][a][b], f[i - 1][b][c] + num[s[a]]);
                    }
                }
            }
        }
    }
    cout << f[n + 2][0][0];
}