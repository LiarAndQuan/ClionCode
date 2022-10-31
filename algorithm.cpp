#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int f[200][200];
int index = 0;
int ma = -1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
                if (f[i][j] >= ma) {
                    ma = f[i][j];
                    index = j - 1;
                }
            } else {
                f[i][j] = 0;
            }
        }
    }
    cout << ma << endl;
    for (int i = index - ma; i < index; i++) {
        cout << a[i];
    }
}