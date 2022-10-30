#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[101];
int f[101];
int n;
int path[101];
int maxindex;

void print(inti) {
    if (path[i]) print(path[i]);
    cout << a[i] << " ";
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j] && f[j] + 1 > f[i]) {
                f[i] = f[j] + 1;
                path[i] = j;//记录前驱节点
            }
        }
        if (f[i] > ans) {
            ans = f[i];
            maxindex = i;
        }
    }
    cout << ans <<endl;
    print(maxindex);
}
