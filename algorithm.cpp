#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int w[100];
        int f[100];
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        f[0] = 0;
        f[1] = w[1];
        for (int i = 2; i <= n; i++) {
            f[i] = max(f[i - 1], f[i - 2] + w[i]);
        }
        cout<<f[n]<<endl;
    }
}