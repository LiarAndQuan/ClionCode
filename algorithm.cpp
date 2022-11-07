#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char s[100];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i + n] = s[i];
    }
    int i = 1, j = 2, k = 0;
    while (i <= n && j <= n) {
        for (k = 0; k < n && s[i + k] == s[j + k]; k++);
        s[i + k] > s[j + k] ? i = i + k + 1 : j = j + k + 1;
        if (i == j) {
            j++;
        }
    }
    cout << min(i, j);
}