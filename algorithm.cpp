#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define M 100000
#define N 100000

struct edge {
    int v;
    int c;
    int ne;
} e[M];

int h[N], idx = 1;
int mf[N], pre[N];
int s, t;

void add(int a,int b,int c) {
    e[++idx] = {b, c, h[a]};
    h[a] = idx;
}

bool bfs() {
    memset(mf, 0, sizeof mf);//初始化每个点的流量上限为0
    queue<int> q;
    q.push(s);
    mf[s] = 1e9;//起点的流量设为无穷大
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {
            int v = e[i].v;
            if (mf[v] == 0 && e[i].c) {//如果这个点没有被访问过并且有流量可以走到这条边
                mf[v] = min(mf[u], e[i].c);//更新
                pre[v] = i;//记录该点的前驱边
                q.push(v);
                if (v == t) {//如果到达了汇点,返回
                    return true;
                }
            }
        }
    }
    return false;
}

int EK() {
    int flow = 0;
    while (bfs()) {//只要能找到可行流就继续找
        int v = t;
        while (v != s) {//逆序更新残留网
            int i = pre[v];
            e[i].c -= mf[t];//前驱边的容量减去相应数值
            e[i ^ 1].c += mf[t];//相反边增加数值
            v = e[i ^ 1].v;//v等于相反边的下一个点
        }
        flow += mf[t];
    }
    return flow;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << EK() <<endl;
}