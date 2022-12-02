#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;\

#define N 100000
vector<int> e[N], ne[N];
int dfn[N], low[N], tot;
stack<int> s;
vector<int> dcc[N];
int cut[N], root, cnt, num, id[N];

void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    s.push(x);
    if (!e[x].size()) {//孤立点
        dcc[++cnt].push_back(x);
        return;
    }
    int child = 0;
    for (int y: e[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {//满足割点的条件
                child++;
                if (x != root || child > 1) {
                    cut[x] = true;
                }
                cnt++;
                int z = -1;
                while (z != y) {//只要这条路满足割点的条件,那就开始出栈
                    z = s.top();
                    s.pop();
                    dcc[cnt].push_back(z);
                }
                dcc[cnt].push_back(x);//x是割点,加入,但不出栈
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
    for (root = 1; root <= n; root++) {
        if (!dfn[root]) {
            tarjan(root);
        }
    }
    num = cnt;
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {//如果是割点,那么给割点编号
            id[i] = ++num;
        }
    }
    for (int i = 1; i <= cnt; i++) {//枚举所有的点双连通分量vdcc
        for (int j = 0; j < dcc[i].size(); j++) {//枚举这个点双连通分量的所有点
            int x = dcc[i][j];
            if (cut[x]) {//找到该vdcc中的割点,给割点的新标号和该vdcc的标号建立一条无向边
                ne[i].push_back(id[x]);
                ne[id[x]].push_back(i);
            }
        }
    }
}