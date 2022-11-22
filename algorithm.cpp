#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define N 100

int n, ans;
int pos[N], c[N], p[N], q[N];


void print() {
    if (ans <= 3) {
        for (int i = 1; i <= n; i++) {
            cout << pos[i] << " ";
        }
        cout << endl;
    }

}


void dfs(int i) {
    if (i > n) {
        ans++;
        print();
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (c[j] || p[i + j] || q[i - j + n]) {
            continue;
        }
        pos[i] = j;
        c[j] = p[i + j] = q[i - j + n] = 1;
        dfs(i + 1);
        c[j] = p[i + j] = q[i - j + n] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    cout << ans;


}