#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define N 10000
struct edge {
    int v;
    int ne;
} e[N];

int h[N], idx;
int color[N];

void add(int a, int b) {
    e[++idx] = {b, h[a]};
    h[a] = idx;
}

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i; i = e[i].ne) {
        int v = e[i].v;
        if (!color[v]) {
            if (dfs(v, 3 - c)) {//染成另一种色
                return 1;
            }
        } else if (color[v] == c) {//如果和他相连的边的颜色和他相同,那么就不符合二分图的定义
            return 1;
        }
    }
    return 0;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (dfs(i, 1)) {
                flag = 1;
                break;
            }
        }
    }
    if (flag) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}