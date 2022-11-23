#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

unordered_map<string,int> d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(string str, string end) {
    queue<string> q;
    q.push(str);
    while (q.size()) {
        auto s = q.front();
        q.pop();
        if (s == end) {
            return d[s];
        }
        int k = s.find('0');
        int x = k / 3;
        int y = k % 3;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx <= 2 && yy >= 0 && yy <= 2) {
                int dis = d[s];
                swap(s[k], s[xx * 3 + yy]);
                if (!d.count(s)) {
                    d[s] = dis + 1;
                    q.push(s);
                }
                swap(s[k], s[xx * 3 + yy]);
            }
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    cout << bfs(str, "123804765");
}