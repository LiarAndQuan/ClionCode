#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


#define N 200000
vector<int> e[N];
int dfn[N], low[N], tot;
int instack[N];
stack<int> s;
int scc[N], cnt;
int in[N], out[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    s.push(u);
    instack[u] = 1;
    for (int v: e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        cnt++;
        int v = -1;
        while (v != u) {
            v = s.top();
            s.pop();
            instack[v] = 0;
            scc[v] = cnt;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        while (1) {
            cin >> v;
            if (v == 0) {
                break;
            }
            e[i].push_back(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j: e[i]) {
            if (scc[i] != scc[j]) {
                in[scc[j]]++;
                out[scc[i]]++;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= cnt; i++) {
        if (!in[i]) {
            a++;
        }
        if (!out[i]) {
            b++;
        }
    }
    cout << a <<endl;//入度为0的点就是需要建立的点
    if (cnt == 1) {//如果只有一个缩点,那么需要特判,否则入度与出度为0的数量都会变为1,输出1,错误
        cout << 0 <<endl;
    } else {
        cout << max(a, b) <<endl;
    }
}