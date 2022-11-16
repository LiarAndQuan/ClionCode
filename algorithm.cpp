#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int fa[10005];

int find(int i) {
    if (fa[i] == i) {
        return i;
    } else {
        return fa[i] = find(fa[i]);
    }
}

void unionset(int x, int y) {
    fa[find(x)] = find(y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 10000; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> z >> x >> y;
        if (z == 1) {
            unionset(x, y);
        } else {
            if (find(x) == find(y)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
}