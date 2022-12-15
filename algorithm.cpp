#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

#define N 2000005

int cnt[N], ans;
int tot = 1, np = 1;
int fa[N], ch[N][26], len[N];
vector<int> e[N];

void extend(int c) {
    //p回跳指针,np新点,q链接点,nq新链接点
    int p = np;//p指向旧点
    np = ++tot;//np是新点
    len[np] = len[p] + 1;//子串出现次数
    cnt[np] = 1;
    for (; p && !ch[p][c]; p = fa[p]) {//p沿链接边往回跳,从旧点向新点建转移边
        ch[p][c] = np;
    }
    if (p == 0) {//如果c是新字符,从新点向根节点建链接边
        fa[np] = 1;
    } else {
        int q = ch[p][c];//q是链接点
        if (len[q] == len[p] + 1) {//若链接点合法,从新点向q建链接边
            fa[np] = q;
        } else {
            int nq = ++tot;//nq是新链接点
            len[nq] = len[p] + 1;//重建nq,q,np的链接边
            fa[nq] = fa[q];
            fa[q] = nq;
            fa[np] = nq;
            //指向q的转移边改为指向nq
            for (; p && ch[p][c] == q; p = fa[p]) {
                ch[p][c] = nq;
            }
            //从q发出的转移边复制给nq
            memcpy(ch[nq], ch[q], sizeof(ch[q]));
        }
    }
}

void dfs(int u) {
    for (auto v: e[u]) {
        dfs(v);
        cnt[u] += cnt[v];
    }
    if (cnt[u] > 1) {
        ans = max(ans, cnt[u] * len[u]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        extend(str[i] - 'a');
    }
    for (int i = 2; i <= tot; i++) {
        e[fa[i]].push_back(i);
    }
    dfs(1);
    cout << ans << endl;
}