#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

string a, b;
int p[201][201];
int f[201][201];
char s[201];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    int m = a.length();
    int n = b.length();

    //动态规划找到最长的并且标记路径
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {//左上
                f[i][j] = f[i - 1][j - 1] + 1;
                p[i][j] = 1;
            } else {//左
                if (f[i][j - 1] > f[i - 1][j]) {
                    f[i][j] = f[i][j - 1];
                    p[i][j] = 2;
                } else {//上
                    f[i][j] = f[i - 1][j];
                    p[i][j] = 3;
                }
            }
        }
    }

    cout << f[m][n] << endl;

    int i = m, j = n, k = f[m][n];

    while (i > 0 && j > 0) {
        if (p[i][j] == 1) {
            s[k--] = a[i - 1];
            i--, j--;
        } else if (p[i][j] == 2) {
            j--;
        } else {
            i--;
        }
    }
    for (i = 1; i <= f[m][n]; i++) {
        cout << s[i] << " ";
    }

}
