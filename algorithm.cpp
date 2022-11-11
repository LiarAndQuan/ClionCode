#include<iostream>

using namespace std;

int ch[1000][2], idx;

void insert(int n) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int j = 1 & (n >> i);
        if (!ch[p][j]) {
            ch[p][j] = ++idx;
        }
        p = ch[p][j];
    }
}

int query(int n) {
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        int j = 1 & (n >> i);
        if (ch[p][!j]) {
            res += 1 << i;
            p = ch[p][!j];
        } else {
            p = ch[p][j];
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    int ma = -1;
    for (int i = 1; i <= n; i++) {
        ma = max(ma, query(a[i]));
    }
    cout << ma;

}