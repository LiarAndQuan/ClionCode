#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 10000
#define M 20000

struct edge {
		int v;
		int ne;
} e[M];

int h[N], idx = 1;
int dfn[N], low[N], tot;
stack<int> s;
int dcc[N], cnt;
int bri[M], d[N];


void add(int a,int b) {
    e[++idx].v = b;
    e[idx].ne = h[a];
    h[a] = idx;
}

void tarjan(int x,int in_edge) {
    dfn[x] = low[x] = ++tot;
    s.push(x);
    for (int i = h[x]; i; i = e[i].ne) {//割边
				int y = e[i].v;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {
                bri[i] = bri[i ^ 1] = true;
            }
        } else if (i != (in_edge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {//缩点
				cnt++;
        while (1) {
						int y = s.top();
            s.pop();
            dcc[y] = cnt;
            if (y == x) {
                break;
            }
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
        add(a, b);
        add(b, a);
    }
    tarjan(1, 0);
    for (int i = 2; i <= idx; i++) {
        if (bri[i]) {
            d[dcc[e[i].v]]++;
        }
    }
		int sum = 0;
    for (int i = 1; i <= cnt; i++) {
        if (d[i] == 1) {
            sum++;
        }
    }
    cout << (sum + 1) / 2;

}