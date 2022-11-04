#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, k;//棋盘行数和国王总数
int cnt;//同一行的合法状态的数量
int s[1 << 12];//同一行的合法状态集
int num[1 << 12];//每个合法状态包含的国王数
long long f[12][144][1 << 12];
//前i行放了j个国王,第i行第a个状态时的方案数

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (inti = 0; i < (1 << n); i++) {
        if (!(i & i >> 1)) {//如果这个状态合法
            s[cnt++] = i;//记录这个状态
            for (intj = 0; j < n; j++) {
                num[i] += (i >> j & 1);//记录这个状态放了几个国王
            }
        }
    }
    f[0][0][0] = 1;//不放国王是一种方案
    for (int i = 1; i <= n+1 ; i++) {//枚举行
        for (int j = 0; j <= k; j++) {//枚举前i行一共的国王数
            for (int a = 0; a < cnt; a++) {//枚举第i行的合法状态
                for (int b = 0; b < cnt; b++) {//枚举第i-1行的合法状态
                    intc = num[s[a]];//第i行第a个状态的国王数
                    //可以继续放国王,不存在同列的1,不存在斜对角的1
                    if ((j >= c) && !(s[b] & s[a]) && !(s[b] & (s[a] << 1)) && !(s[b] & (s[a] >> 1))) {
                        f[i][j][a] += f[i - 1][j - c][b];
                    }
                }
            }
        }
    }
    cout << f[n + 1][k][0] <<endl;
}