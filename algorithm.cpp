#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


vector<int> e[100], tp;
int c[100];//染色数组
int n, m;

bool dfs(int x) {
    c[x] = -1;
    for (int i: e[x]) {
        if (c[i] == -1) {
            return 0;
        } else if (c[i] == 0) {
            if (!dfs(i)) {
                return 0;
            }
        }
    }
    c[x] = 1;
    tp.push_back(x);
    return 1;
}

bool toposort() {
    memset(c, 0, sizeof(c));
    for (int x = 1; x <= n; x++) {
        if (!c[x]) {
            if (!dfs(x)) {
                return 0;
            }
        }
    }
    reverse(tp.begin(), tp.end());
    return 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
    }
    if (!toposort()) {
        cout << "Error" <<endl;
    } else {
        for (int i: tp) {
            cout << i << " ";
        }
    }
}