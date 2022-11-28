#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 100000
vector<int> e[N];
int dfn[N], low[N], tot;
stack<int> s;
int ins[N];
int scc[N], siz[N], cnt;

void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    s.push(x);
    ins[x] = 1;
    for (int y: e[x]) {
        if (!dfn[y]) {//如果y没有访问过
            tarjan(y);
            low[x] = min(low[x], low[y]);//回x的时候用y更新low
        } else if (ins[y]) {//访问过并且在栈中
            low[x] = min(low[x], dfn[y]);//更新low
        }
    }
    //离开x的时候记录scc
    if (dfn[x] == low[x]) {
        int y = -1;
        cnt++;//scc编号
        while (x != y) {
            y = s.top();
            s.pop();
            ins[y] = 0;
            scc[y] = cnt;
            siz[cnt]++;
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
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);

        }
    }
    int sum = 0;
    for (int i = 1; i <= cnt; i++) {
        if (siz[i] > 1) {
            sum++;
        }
    }
    cout << sum;
}