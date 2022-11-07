#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[34], f[34][34], k, b;
//f[i][j]表示在i个位置上放j个1的组合数.

void init() {
    for (int i = 0; i < 34; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i < 34; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
    }
}

int dp(int n) {
    if (!n) {
        return 0;
    }
    int cnt = 0;
    while (n) {
        a[++cnt] = n % b;
        n /= b;
    }
    int res = 0, last = 0;
    for (int i = cnt; i >= 1; i--) {
        int x = a[i];
        if (x) {
            res += f[i - 1][k - last];
            if (x > 1) {
                if (k - last - 1 >= 0) {
                    res += f[i - 1][k - last - 1];
                }
                break;
            } else {
                last++;
                if (last > k) {
                    break;
                }
            }
        }
        if (i == 1 && last == k) {
            res++;
        }
    }
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int l, r;
    cin >> l >> r >> k >> b;
    cout << dp(r) - dp(l - 1);
}