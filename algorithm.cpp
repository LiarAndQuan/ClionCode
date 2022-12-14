#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


struct enmy {
    double x;
    double y;
    double r;
} e[1000];

int is[100][100];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, r;
    cin >> n >> k >> r;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[i].x = a;
        e[i].y = b;
        e[i].r = c;
        is[a][b] = 1;
    }

    int sum = 0;

    while (k--) {
        int ma = 0;
        int pi, pj;
        vector<int> v[20][20];
        for (int i = 0; i <= 15; i++) {
            for (int j = 0; j <= 15; j++) {
                for (int x = 1; x <= n; x++) {
                    double a = e[x].x;
                    double b = e[x].y;
                    double c = e[x].r;
                    if (!is[(int) a][(int) b]) {//如果敌人不存在
                        continue;
                    }
                    if ((a - i) * (a - i) + (b - j) * (b - j) <=
                        (r + c) * (r + c)) {//如果在覆盖范围内
                        v[i][j].push_back(x);
                    }
                }
                if (v[i][j].size() >= ma) {
                    pi = i;
                    pj = j;
                    ma = v[i][j].size();
                }
            }
        }
        for (int i: v[pi][pj]) {
            is[(int) e[i].x][(int) e[i].y] = 0;
        }
        sum += v[pi][pj].size();
    }
    cout << min(sum, n) << endl;
}