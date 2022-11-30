#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 100000
vector<int> e[N];
int dfn[N], low[N], tot;
int root;
int cut[N];


void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    int child = 0;
    for (int y: e[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                child++;
                if (x != root || child > 1) {
                    cut[x] = true;
                }
            }
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            sum++;
        }
    }
    cout << sum <<endl;
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            cout << i << " ";
        }
    }
}