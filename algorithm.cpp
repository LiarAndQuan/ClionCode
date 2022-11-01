#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    int res = -1;
    cin >> n >> m;
    int nums[100];
    int q[100];

    int h = 0, t = 0;
    q[0] = 0;//提前给q[0]赋值,表示从第一个开始前m个最小值为0

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (h <= t && i - q[h] > m) {
            h++;
        }
        res = max(res, nums[i] - nums[q[h]]);
        while (h <= t && nums[i] <= nums[q[t]]) {
            t--;
        }
        q[++t] = i;
    }

    cout << res;
}