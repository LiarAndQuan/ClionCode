#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int a[12], f[12][10];

void init() {
    for (int i = 0; i <= 9; i++) {
        f[1][i] = 1;
    }
    for (int i = 2; i < 12; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(k - j) >= 2) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }
}

int dp(int x) {
    if (!x) {
        return 0;
    }
    int cnt = 0;
    while (x) {
        a[++cnt] = x % 10;
        x /= 10;
    }
    int res = 0, last = -2;
    for (inti = cnt; i >= 1; i--) {
        int now = a[i];
        for (int j = (i == cnt); j < now; j++) {
            if (abs(j - last) >= 2) {
                res += f[i][j];
            }
        }
        if (abs(now - last) < 2) {
            break;
        }
        last = now;
        if (i == 1) {
            res++;
        }
    }
    for (int i = 1; i < cnt; i++) {
        for (int j = 1; j <= 9; j++) {
            res += f[i][j];
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) <<endl;

}