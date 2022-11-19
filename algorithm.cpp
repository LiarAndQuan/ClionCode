#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


int ch[1000005][26], ne[1000005], cnt[1000005];
int idx;


void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (ch[0][i]) {
            q.push(ch[0][i]);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            int v = ch[u][i];
            if (v) {
                ne[v] = ch[ne[u]][i];//给子节点建立回跳边
                q.push(v);
            } else {
                ch[u][i] = ch[ne[u]][i];//给自己建立转移边
            }
        }
    }
}


int query(string s) {
    int ans = 0;
    for (int k = 0, i = 0; k < s.length(); k++) {
        i = ch[i][s[k] - 'a'];//i沿着树边或者转移边走
        for (int j = i; j && cnt[j] != -1; j = ne[j]) {//j沿着回跳边走
            ans += cnt[j];
            cnt[j] = -1;
        }

    }
    return ans;
}

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.length(); i++) {
        int j = s[i] - 'a';
        if (!ch[p][j]) {
            ch[p][j] = ++idx;
        }
        p = ch[p][j];
    }
    cnt[p]++;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        insert(a);
    }
    string cm;
    cin >> cm;
    build();
    cout << query(cm);

}