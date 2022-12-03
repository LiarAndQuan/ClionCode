#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define M 1000006
#define N 1000006

struct edge {
    int v;
    int c;
    int ne;
} e[M];

int h[N], idx = 1;
int s, t;
int d[N], cur[N];

void add(int a, int b, int c) {
    e[++idx] = {b, c, h[a]};
    h[a] = idx;
}

bool bfs() {//寻找增广路,并且按照图层划分
    memset(d, 0, sizeof d);//每一个图层置0
    queue<int> q;
    q.push(s);
    d[s] = 1;//源点图层为1
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {//枚举边
            int v = e[i].v;
            if (d[v] == 0 && e[i].c) {//如果没访问过并且有边可以去
                d[v] = d[u] + 1;
                q.push(v);
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

int dfs(int u, int mf) {
    if (u == t) {
        return mf;
    }
    int sum = 0;
    for (int i = cur[u]; i; i = e[i].ne) {//当前弧优化,cur[u]存的是之前u点最后访问的一条边,因为已经访问过的边不需要再访问
        cur[u] = i;
        int v = e[i].v;
        if (d[v] == d[u] + 1 && e[i].c) {//如果在下一层并且有路可以走
            int f = dfs(v, min(mf, e[i].c));//对子节点dfs,mf去较小值
            e[i].c -= f;//构建残余网
            e[i ^ 1].c += f;
            sum += f;
            mf -= f;//余量减小
            if (mf == 0) {
                break;
            }
        }
    }
    if (sum == 0) {//说明这个点不能到达t点,使其无法访问即可
        d[u] = 0;
    }
    return sum;
}

int dinic() {
    int flow = 0;
    while (bfs()) {//如果有可行流
        memcpy(cur, h, sizeof h);//每次遍历之前都重置cur
        flow += dfs(s, 1e9);
    }
    return flow;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << dinic();

}