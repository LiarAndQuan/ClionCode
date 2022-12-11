#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> e[10000];
bool is[100005];

struct node {
    int notion;
    int a[10] = {0};
} arr[100000];

int k;

int *dfs(int u, int par) {
    for (int i: e[u]) {
        if (i == par) {
            continue;
        } else {
            int *p = dfs(i, u);
            for (int j = 1; j <= k + 1; j++) {
                arr[u].a[j] += p[j];
            }
            free(p);
        }
    }
    int *p = (int *) malloc(4 * (10));
    for (int i = 1; i <= k + 1; i++) {
        p[i] = arr[u].a[i];
    }
    return p;
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 1; i <= 10000; i++) {//素数
        for (int j = 2; j <= (int) sqrt(i) + 1; j++) {
            if (i % j == 0) {
                is[i] = true;
                break;
            }
        }
    }
    is[1] = true;
    is[2] = false;


    int n;
    cin >> n >> k;

    int temp;

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (is[temp]) {//不是
            arr[i].notion = temp % k + 2;
            arr[i].a[temp % k + 2] = 1;
        } else {
            arr[i].notion = 1;
            arr[i].a[1] = 1;
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int q;
    cin >> q;
    dfs(1, 0);

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << arr[x].notion << " " << arr[x].a[y] << endl;
    }

}