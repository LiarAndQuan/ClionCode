#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int nums[100];
    int q[100];
    int m;
    cin >> n >> m;
    int h = 0, t = -1;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (h <= t && i - q[h] > m - 1) {
            h++;
        }
        while (h <= t && nums[i] >= nums[q[t]]) {
            t--;
        }
        q[++t] = i;
        if (i > m - 1) {
            cout << nums[q[h]];
        }
    }
}
