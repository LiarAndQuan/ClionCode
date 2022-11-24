#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, m;
vector<int> e[100], tp;
int din[100];


bool toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (din[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int cur = q.front();
        q.pop();
        tp.push_back(cur);
        for (int i: e[cur]) {
            if (--din[i] == 0) {
                q.push(i);
            }
        }
    }
    return tp.size() == n;//如果拓扑序列里面的值的个数等于n那么就无环
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        din[b]++;
    }
    if (!toposort()) {//如果有环存在
        cout << "ERROR" <<endl;
    } else {
        for (int x: tp) {
            cout << x << " ";
        }
        cout <<endl;
    }

}